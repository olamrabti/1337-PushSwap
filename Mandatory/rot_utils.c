/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:17:40 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/29 14:39:54 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **stack, char *print)
{
	t_stack	*temp;

	if (!stack || list_len(stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->nxt;
	(*stack)->prv = NULL;
	node_addback(stack, temp);
	if (*print)
		write(1, print, 3);
}

void	rotate_both(t_stack **b, t_stack **a, char *print)
{
	rotate_stack(b, "");
	rotate_stack(a, "");
	if (*print)
		write(1, print, 3);
}
