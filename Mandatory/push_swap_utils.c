/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:33:25 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/10 10:28:56 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_stack **list)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	if (!list || !*list)
		return (0);
	tmp = *list;
	while (tmp)
	{
		count++;
		tmp = tmp->nxt;
	}
	return (count);
}

void	free_var(t_var *var)
{
	free(var->sub);
	free(var->indexes);
	free(var->size);
}

void	rearrange_a(t_stack **a, int i)
{
	t_stack	*tmp;

	update_pos(a);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index == i)
			break ;
		tmp = tmp->nxt;
	}
	while ((*a)->index != i)
	{
		if (tmp->pos > list_len(a) / 2)
			rev_rot_stack(a, "rra\n");
		else
			rotate_stack(a, "ra\n");
	}
}

void	from_a_to_b(t_stack **a, t_stack **b, t_var *var)
{
	int	*lsub;
	int	pivot;

	lsub = lsub_algo(var);
	pivot = list_len(a) / 2;
	while (var->lsub_len < list_len(a))
	{
		if (!is_in_lsub(*a, var, lsub))
		{
			push_to_stack(b, a, "pb\n");
			if ((*b)->index < pivot)
				rotate_stack(b, "rb\n");
		}
		else
			rotate_stack(a, "ra\n");
	}
	free(lsub);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*a)->index)
		rearrange_a(a, 0);
	push_to_stack(b, a, "pb\n");
	if (list_len(a) > 3 && (*a)->index != 1)
		rearrange_a(a, 1);
	if (is_sorted(a))
	{
		push_to_stack(a, b, "pa\n");
		return ;
	}
	push_to_stack(b, a, "pb\n");
	tmp = *a;
	while (tmp)
	{
		tmp->index -= 2;
		tmp = tmp->nxt;
	}
	sort_three(a);
	push_to_stack(a, b, "pa\n");
	push_to_stack(a, b, "pa\n");
}
