/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:33:25 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/19 17:50:38 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_len(t_stack **list)
{
    size_t count;
    t_stack *tmp;

    count = 0;
    if (!list || !*list)
        return 0;
    tmp = *list;
    while (tmp)
    {
        count++;
        tmp = tmp->nxt;
    }
    return count;
}


