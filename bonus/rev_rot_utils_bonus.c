/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:29:59 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/11 11:28:35 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	list_len(t_stack **list)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	if (!list || !*list)
		return (0);
	tmp = *list;
	while (tmp)
	{
		count++;
		tmp = tmp->nxt;
	}
	return (count);
}

void	rev_rot_stack(t_stack **stack, char *print)
{
	t_stack	*temp;

	if (!stack || !*stack || list_len(stack) < 2)
		return ;
	temp = *stack;
	while (temp->nxt != NULL)
		temp = temp->nxt;
	temp->prv->nxt = NULL;
	temp->prv = NULL;
	node_addfront(stack, temp);
	if (*print)
		write(1, print, 4);
}

void	rev_rot_both(t_stack **b, t_stack **a, char *print)
{
	rev_rot_stack(b, "");
	rev_rot_stack(a, "");
	if (*print)
		write(1, print, 4);
}
