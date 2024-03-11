/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:08:28 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/09 16:05:53 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(long value, size_t index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->prv = NULL;
	node->nxt = NULL;
	node->num = value;
	node->index = index;
	node->target_pos = index;
	return (node);
}

int	node_addfront(t_stack **list, t_stack *new)
{
	if (!list || !new)
		return (1);
	new->prv = NULL;
	if (*list)
	{
		(*list)->prv = new;
		new->nxt = *list;
	}
	else
		new->nxt = NULL;
	*list = new;
	return (0);
}

int	node_addback(t_stack **list, t_stack *new)
{
	t_stack	*temp;

	if (!list || !new)
		return (1);
	new->nxt = NULL;
	if (!*list)
	{
		*list = new;
		return (0);
	}
	temp = *list;
	while (temp->nxt != NULL)
		temp = temp->nxt;
	temp->nxt = new;
	new->prv = temp;
	return (0);
}

int	delete_node(t_stack *node)
{
	if (!node)
		return (1);
	if (node->prv)
		node->prv->nxt = node->nxt;
	if (node->nxt)
		node->nxt->prv = node->prv;
	free(node);
	node = NULL;
	return (0);
}

void	remove_list(t_stack **list)
{
	t_stack	*curr;
	t_stack	*next;

	if (!list || !*list)
		return ;
	if (!(*list)->nxt)
	{
		delete_node(*list);
		*list = NULL;
		return ;
	}
	curr = *list;
	while (curr != NULL)
	{
		next = curr->nxt;
		delete_node(curr);
		curr = next;
	}
	*list = NULL;
}
