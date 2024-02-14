/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:33:25 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/14 12:46:17 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t list_len(t_stack **list)
{
    size_t count;
    t_stack *tmp;

    count = 0;
    if (!list || !*list)
        return 0;
    tmp = *list;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->nxt;
    }
    return count;
}

void update_indexes(t_stack **stack)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = *stack;
    if (!stack)
        return;
    while (tmp)
    {
        tmp->index = i++;
        tmp = tmp->nxt;
    }
}
