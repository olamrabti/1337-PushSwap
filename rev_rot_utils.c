/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:29:59 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/19 17:21:05 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void rev_rot_stack(t_stack **stack)
{
   t_stack *temp;
    if (!stack || !*stack || list_len(stack) < 2)
        return;
    temp = *stack;
    while (temp->nxt != NULL)
        temp = temp->nxt;
    temp->prv->nxt = NULL;
    temp->prv = NULL;  
    node_addfront(stack, temp);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// just swap args


// rrr : rra and rrb at the same time

void rev_rot_both(t_stack **b, t_stack **a)
{
    rev_rot_stack(b);
    rev_rot_stack(a);
}