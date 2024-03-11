/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:17:40 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/09 17:28:53 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
