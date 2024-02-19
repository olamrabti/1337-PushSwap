/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:11:51 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/19 17:35:23 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_cost(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;

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
                break;
            }
            tmp_a = tmp_a->nxt;
        }
        tmp_b = tmp_b->nxt;
    }
}

void execute_moves(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int cheapest;
    int b_moves;
    int a_moves;

    tmp_b = *b;
    tmp_a = *a;
    cheapest = INT_MAX;

    // look for smallest cost in b
    while (tmp_b)
    {
        if (tmp_b->cost < cheapest)
        {
            b_moves = tmp_b->moves;
            a_moves = tmp_b->target_moves;
            cheapest = tmp_b->cost;
        }
        tmp_b = tmp_b->nxt;
    }
    tmp_b = *b;
    tmp_a = *a;

    while (a_moves || b_moves)
    {
        if (b_moves > 0 && a_moves > 0)
        {
            rotate_both(b, a);
            write(1, "rr\n", 3);
            b_moves--;
            a_moves--;
        }
        if (b_moves < 0 && a_moves < 0)
        {
            rev_rot_both(b, a);
            write(1, "rrr\n",4);
            b_moves++;
            a_moves++;
        }
        if (b_moves > 0)
        {
            rotate_stack(b);
            write(1, "rb\n", 3);
            b_moves--;
        }
        else if (b_moves < 0)
        {
            rev_rot_stack(b);
            write(1, "rrb\n",4);
            b_moves++;
        }
        if (a_moves > 0)
        {
            rotate_stack(a);
            write(1, "ra\n", 3);
            a_moves--;
        }
        else if (a_moves < 0)
        {
            rev_rot_stack(a);
            write(1, "rra\n",4);
            a_moves++;
        }
    }
    push_to_stack(a, b);
    write(1, "pa\n", 3);
}