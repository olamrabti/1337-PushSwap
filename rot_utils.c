/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:17:40 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/14 12:35:54 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
    // The first element becomes the last one.

void rotate_stack(t_stack **stack)
{
    t_stack *temp;
    
    if (!stack || list_len(stack) < 2)
        return ;
    temp = *stack;
    *stack = (*stack)->nxt;
    (*stack)->prv = NULL;
    node_addback(stack, temp);
    update_indexes(stack);
}

void rotate_both(t_stack **b, t_stack **a)
{
    rotate_stack(b);
    rotate_stack(a);
}