/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:07:42 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/29 11:07:52 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->nxt;
	}
}

void	update_moves(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (i <= list_len(stack) / 2)
		{
			tmp->cost = i;
			tmp->moves = i;
		}
		else
		{
			tmp->moves = -(list_len(stack) - i);
			tmp->cost = -tmp->moves;
		}
		i++;
		tmp = tmp->nxt;
	}
}

void	find_closest_bigger(t_stack **a, t_stack *tmp_b)
{
	t_stack	*tmp_a;
	int		closest_bigger;

	tmp_a = *a;
	closest_bigger = INT_MAX;
	while (tmp_a)
	{
		if (tmp_a->index > tmp_b->index && tmp_a->index < closest_bigger)
		{
			closest_bigger = tmp_a->index;
			tmp_b->target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->nxt;
	}
}

void	find_smallest_index(t_stack **a, t_stack *tmp_b)
{
	t_stack	*tmp_a;
	int		smallest_index;

	tmp_a = *a;
	smallest_index = tmp_a->index;
	while (tmp_a)
	{
		if (tmp_a->index <= smallest_index)
		{
			smallest_index = tmp_a->index;
			tmp_b->target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->nxt;
	}
}

void	update_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		closest_bigger;

	tmp_b = *b;
	while (tmp_b)
	{
		closest_bigger = INT_MAX;
		tmp_b->target_pos = -1;
		find_closest_bigger(a, tmp_b);
		if (tmp_b->target_pos == -1)
			find_smallest_index(a, tmp_b);
		tmp_b = tmp_b->nxt;
	}
}
