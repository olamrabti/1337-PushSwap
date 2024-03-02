/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:33:09 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/01 21:31:46 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack **a, t_stack **b)
{
	t_var	var;

	if (init_variables(a, &var))
		return (1);
	update_indexes(a, &var);
	if (list_len(a) == 3)
		return (sort_three(a), free_var(&var), free(var.numbers), 0);
	if (list_len(a) == 5)
		return (sort_five(a, b), free_var(&var), free(var.numbers), 0);
	from_a_to_b(a, b, &var);
	while (list_len(b))
	{
		update_pos(a);
		update_pos(b);
		update_target_pos(a, b);
		update_moves(b);
		update_moves(a);
		update_cost(a, b);
		execute_moves(a, b);
	}
	if ((*a)->index)
		rearrange_a(a, 0);
	return (free(var.numbers), 0);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (parse_args(ac, av, &a) || ac <= 1 || check_doubles(&a))
		return (remove_list(&a), write(1, "error\n", 6), -1);
	if (!is_sorted(&a))
	{
		if (list_len(&a) == 2)
			swap_elements(&a, "sa\n");
		else
		{
			push_swap(&a, &b);
			remove_list(&b);
		}
	}
	return (remove_list(&a), 0);
}
