/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:29:53 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/19 17:24:29 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// pa (push a): Take the first element at the top of b and put it at the top of a.
    // Do nothing if b is empty.
void push_to_stack(t_stack **push_to, t_stack **from)
{
    t_stack *temp;
    
    if (!push_to || !from || !*from)
        return ;
    temp = *from; // first in b
    *from = (*from)->nxt;
    if (*from)
        (*from)->prv = NULL;
    node_addfront(push_to, temp);
}