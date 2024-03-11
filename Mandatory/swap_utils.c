/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:30:10 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/29 14:39:01 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elements(t_stack **stack, char *print)
{
	t_stack	*second;

	if (!stack || list_len(stack) < 2)
		return ;
	second = (*stack)->nxt;
	(*stack)->nxt = second->nxt;
	(*stack)->prv = second;
	second->nxt = (*stack);
	second->prv = NULL;
	*stack = second;
	if (*print)
		write(1, print, 3);
}

void	swap_both(t_stack **a, t_stack **b, char *print)
{
	swap_elements(a, "");
	swap_elements(b, "");
	if (*print)
		write(1, print, 3);
}
