/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:44:27 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/11 12:41:08 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	if (!str || !*str)
		return (0);
	return (1 + ft_strlen(str + 1));
}

int	check_args(t_parse *pv, t_stack **a)
{
	int	num;

	num = 0;
	pv->j = 0;
	while (pv->sp[pv->j])
	{
		pv->checker = 1;
		ft_atoi(pv->sp[pv->j], &pv->checker);
		if (pv->checker)
		{
			while (pv->sp[pv->j++])
				;
			ft_free(pv->sp, pv->j);
			return (remove_list(a), 1);
		}
		pv->j++;
	}
	pv->k = 0;
	while (pv->k < pv->j)
	{
		num = ft_atoi(pv->sp[pv->k++], &pv->checker);
		node_addback(a, create_node(num, -1));
	}
	return (ft_free(pv->sp, pv->k + 1), 0);
}

int	parse_args(int ac, char *av[], t_stack **a)
{
	t_parse	pv;

	pv.i = 1;
	while (pv.i < ac)
	{
		pv.checker = 1;
		pv.sp = ft_split(av[pv.i], ' ');
		if (!pv.sp || !*(pv.sp))
			return (free(pv.sp), -1);
		if (check_args(&pv, a))
			return (-2);
		pv.i++;
	}
	return (0);
}

int	check_doubles(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!stack || !(*stack))
		return (-1);
	tmp = *stack;
	while (tmp)
	{
		next = tmp->nxt;
		while (next)
		{
			if (tmp->num == next->num)
				return (-2);
			next = next->nxt;
		}
		tmp = tmp->nxt;
	}
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return (-1);
	tmp = *stack;
	while (tmp->nxt)
	{
		if (tmp->num > tmp->nxt->num)
			return (0);
		tmp = tmp->nxt;
	}
	return (-2);
}
