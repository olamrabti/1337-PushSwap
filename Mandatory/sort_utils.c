/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:08:12 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/29 12:08:04 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_numbers(t_stack **stack, int *numbers)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		numbers[i++] = tmp->num;
		tmp->index = -1;
		tmp = tmp->nxt;
	}
}

void	fill_indexes(t_stack **stack, int *indexes)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		indexes[i++] = tmp->index;
		tmp = tmp->nxt;
	}
}

void	bubble_sort(t_var *var)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < var->len - 1)
	{
		j = 0;
		while (j < var->len - i - 1)
		{
			if (var->numbers[j] > var->numbers[j + 1])
			{
				temp = var->numbers[j];
				var->numbers[j] = var->numbers[j + 1];
				var->numbers[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	update_indexes(t_stack **stack, t_var *var)
{
	int		i;
	t_stack	*tmp;

	tmp = *stack;
	bubble_sort(var);
	if (!stack)
		return ;
	while (tmp)
	{
		i = 0;
		while (i < var->len)
		{
			if (tmp->num == var->numbers[i])
			{
				tmp->index = i;
				break ;
			}
			else
				i++;
		}
		tmp = tmp->nxt;
	}
	fill_indexes(stack, var->indexes);
}

void	sort_three(t_stack **stack)
{
	if (!(*stack)->index)
	{
		rev_rot_stack(stack, "rra\n");
		swap_elements(stack, "sa\n");
	}
	else if (!(*stack)->nxt->index)
	{
		if ((*stack)->index == 2)
			rotate_stack(stack, "ra\n");
		else
			swap_elements(stack, "sa\n");
	}
	else
	{
		if ((*stack)->index == 1)
			rev_rot_stack(stack, "rra\n");
		else
		{
			rotate_stack(stack, "ra\n");
			swap_elements(stack, "sa\n");
		}
	}
}
