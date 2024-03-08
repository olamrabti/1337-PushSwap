/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsub_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:12 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/08 17:23:42 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest(int *arr, size_t size)
{
	int	highest;

	if (!size)
		return (1);
	highest = size;
	while (size)
	{
		if (arr[highest] <= arr[size])
			highest = size;
		size--;
	}
	return (highest);
}

int	init_variables(t_stack **stack, t_var *var)
{
	if (!stack || !var->len)
		return (1);
	var->len = list_len(stack);
	var->size = malloc(var->len * sizeof(int));
	if (!var->size)
		return (1);
	var->sub = malloc(var->len * sizeof(int));
	if (!var->sub)
		return (free(var->size), 1);
	var->indexes = malloc(var->len * sizeof(int));
	if (!var->indexes)
		return (free(var->size), free(var->sub), 1);
	var->numbers = malloc(var->len * sizeof(int));
	if (!var->numbers)
		return (free_var(var), 1);
	fill_numbers(stack, var->numbers);
	var->i = 0;
	var->size[var->len] = 0;
	while (var->i < var->len)
		var->size[var->i++] = 1;
	var->i = 1;
	var->sub[0] = 0;
	var->j = 0;
	return (0);
}

int	*get_lsub(t_var *var)
{
	int	*lsub;

	var->lsub_len = var->size[var->highest];
	lsub = malloc(var->lsub_len * sizeof(int));
	if (!lsub)
		return (free_var(var), NULL);
	var->i = var->highest;
	var->j = var->lsub_len;
	while (var->j)
	{
		lsub[--(var->j)] = var->indexes[var->i];
		var->i = var->sub[var->i];
	}
	return (lsub);
}

int	*lsub_algo(t_var *var)
{
	int	*lsub;

	while (var->i < var->len)
	{
		while (var->j < var->i)
		{
			if (var->indexes[var->j] <= var->indexes[var->i]
				&& var->size[var->j] + 1 > var->size[var->i])
			{
				var->size[var->i] = var->size[var->j] + 1;
				var->sub[var->i] = var->j;
			}
			var->j++;
		}
		var->i++;
		var->j = 0;
	}
	var->highest = find_highest(var->size, var->len);
	lsub = get_lsub(var);
	return (free_var(var), lsub);
}

int	is_in_lsub(t_stack *stack, t_var *var, int *lsub)
{
	int	i;

	i = 0;
	while (i < var->lsub_len)
	{
		if (stack->index == lsub[i++])
			return (1);
	}
	return (0);
}
