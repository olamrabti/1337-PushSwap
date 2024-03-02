/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:11:51 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/29 09:48:22 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_b->target_pos == tmp_a->pos)
			{
				tmp_b->cost += tmp_a->cost;
				tmp_b->target_moves = tmp_a->moves;
				break ;
			}
			tmp_a = tmp_a->nxt;
		}
		tmp_b = tmp_b->nxt;
	}
}

void	update_cheapest(t_stack **stack, t_moves *current)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->cost < current->cheapest)
		{
			current->b_moves = tmp->moves;
			current->a_moves = tmp->target_moves;
			current->cheapest = tmp->cost;
		}
		tmp = tmp->nxt;
	}
}

void	execute_both(t_stack **a, t_stack **b, t_moves *current)
{
	while (current->a_moves > 0 && current->b_moves > 0)
	{
		rotate_both(b, a, "rr\n");
		current->a_moves--;
		current->b_moves--;
	}
	while (current->a_moves < 0 && current->b_moves < 0)
	{
		rev_rot_both(b, a, "rrr\n");
		current->a_moves++;
		current->b_moves++;
	}
}

void	execute_separately(t_stack **a, t_stack **b, t_moves *current)
{
	while (current->a_moves != 0 || current->b_moves != 0)
	{
		if (current->b_moves > 0)
		{
			rotate_stack(b, "rb\n");
			current->b_moves--;
		}
		else if (current->b_moves < 0)
		{
			rev_rot_stack(b, "rrb\n");
			current->b_moves++;
		}
		else if (current->a_moves > 0)
		{
			rotate_stack(a, "ra\n");
			current->a_moves--;
		}
		else if (current->a_moves < 0)
		{
			rev_rot_stack(a, "rra\n");
			current->a_moves++;
		}
	}
}

void	execute_moves(t_stack **a, t_stack **b)
{
	t_moves	current;

	current.b_moves = 0;
	current.a_moves = 0;
	current.cheapest = INT_MAX;
	update_cheapest(b, &current);
	execute_both(a, b, &current);
	execute_separately(a, b, &current);
	push_to_stack(a, b, "pa\n");
}
