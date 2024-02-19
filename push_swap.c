/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:33:09 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/19 17:52:33 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_pos(t_stack **stack)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        tmp->pos = i++;
        tmp = tmp->nxt;
    }
}

void update_moves(t_stack **stack)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        if (i < list_len(stack) / 2)
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

void update_target_pos(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int closest_bigger;

    tmp_b = *b;
    while (tmp_b)
    {
        tmp_a = *a;
        closest_bigger = INT_MAX;
        tmp_b->target_pos = -1;
        while (tmp_a)
        {
            if (tmp_a->index > tmp_b->index && tmp_a->index < closest_bigger)
            {
                closest_bigger = tmp_a->index;
                tmp_b->target_pos = tmp_a->pos;
            }
            tmp_a = tmp_a->nxt;
        }
        // If no bigger number found, assign the smallest index in stack A
        if (tmp_b->target_pos == -1)
        {
            tmp_a = *a;
            while (tmp_a)
            {
                if (tmp_a->index < closest_bigger)
                {
                    closest_bigger = tmp_a->index;
                    tmp_b->target_pos = tmp_a->pos;
                }
                tmp_a = tmp_a->nxt;
            }
        }
        tmp_b = tmp_b->nxt;
    }
}

int push_swap(t_stack **a, t_stack **b)
{
    t_var var;
    int *LIS;
    int pivot;

    if (init_variables(a, &var))
        return 1;
    update_indexes(a, &var);
    pivot = list_len(a) / 2;
    LIS = lis_algo(&var);
    while (list_len(a) > var.LIS_len)
    {
        if (!is_in_LIS(*a, &var, LIS))
        {
            push_to_stack(b, a);
            write(1, "pb\n", 3);
            if ((*b)->index >= pivot)
            {
                rotate_stack(b);
                write(1, "rb\n", 3);
            }
        }
        rotate_stack(a);
        write(1, "ra\n", 3);
    }
    while (list_len(b))
    {
        update_pos(a);
        update_pos(b);
        update_target_pos(a, b);
        update_moves(b);
        update_moves(a);
        update_cost(a, b);
        execute_moves(a, b);
    }
    while ((*a)->index)
    {
        rotate_stack(a);
        write(1, "ra\n", 3);
    }
    return 0;
}
