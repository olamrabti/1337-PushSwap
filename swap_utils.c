/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:30:10 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/14 12:36:12 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
    // Do nothing if there is only one or no elements.
void swap_elements(t_stack **stack)
{
    t_stack *second;
    if (!stack || list_len(stack) < 2)
        return ;
    second = (*stack)->nxt;
    (*stack)->nxt = second->nxt;
    (*stack)->prv = second;
    second->nxt = (*stack);
    second->prv = NULL;
    *stack = second;
    update_indexes(stack);
}
// sb (swap b): Swap the first 2 elements at the top of stack b.
    // Do nothing if there is only one or no elements.

// ss : sa and sb at the same time.
void swap_both(t_stack **a , t_stack **b)
{
    swap_elements(a);
    swap_elements(b);
}