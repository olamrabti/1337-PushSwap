/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:29:53 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/09 17:29:00 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_to_stack(t_stack **push_to, t_stack **from, char *print)
{
	t_stack	*temp;

	if (!push_to || !from || !*from)
		return ;
	temp = *from;
	*from = (*from)->nxt;
	if (*from)
		(*from)->prv = NULL;
	node_addfront(push_to, temp);
	if (*print)
		write(1, print, 3);
}
