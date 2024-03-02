/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:10 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/02 11:59:48 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

int	apply_instruction(t_stack **a, t_stack **b, char *instr)
{
	if (!ft_strcmp(instr, "pa"))
		push_to_stack(a, b, "");
	else if (!ft_strcmp(instr, "pb"))
		push_to_stack(b, a, "");
	else if (!ft_strcmp(instr, "sa"))
		swap_elements(a, "");
	else if (!ft_strcmp(instr, "sb"))
		swap_elements(b, "");
	else if (!ft_strcmp(instr, "ss"))
		swap_both(b, a, "");
	else if (!ft_strcmp(instr, "ra"))
		rotate_stack(a, "");
	else if (!ft_strcmp(instr, "rb"))
		rotate_stack(b, "");
	else if (!ft_strcmp(instr, "rr"))
		rotate_both(b, a, "");
	else if (!ft_strcmp(instr, "rra"))
		rev_rot_stack(a, "");
	else if (!ft_strcmp(instr, "rrb"))
		rev_rot_stack(b, "");
	else if (!ft_strcmp(instr, "rrr"))
		rev_rot_both(b, a, "");
	else
		return (-1);
	return (0);
}

int	get_instructions(t_stack **a, t_stack **b, char *store)
{
	int		i;
	int		j;
	char	**sp;

	i = 0;
	j = 0;
	sp = ft_split(store, '\n');
	free(store);
	if (!sp)
		return (-3);
	if (!*sp)
		return (free(sp), -2);
	while (sp[i])
	{
		if (apply_instruction(a, b, sp[i++]) == -1)
		{
			while (sp[j++])
				;
			return (ft_free(sp, j), -1);
		}
	}
	while (sp[j++])
		;
	return (ft_free(sp, j), 0);
}

void	read_input(char **store)
{
	char	*buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		*store = ft_strjoin(*store, buffer);
		if (!*store)
		{
			free(buffer);
			return ;
		}
		free(buffer);
		buffer = get_next_line(0);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*store;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	if (parse_args(ac, av, &a) || check_doubles(&a))
		return (remove_list(&a), write(1, "error\n", 6), -1);
	store = malloc(1);
	if (!store)
		return (remove_list(&a), -1);
	store[0] = '\0';
	read_input(&store);
	if (list_len(&a) && get_instructions(&a, &b, store) == -1)
		return (remove_list(&b), remove_list(&a), write(1, "error\n", 6), -1);
	if (is_sorted(&a) && list_len(&b) == 0)
		return (remove_list(&b), remove_list(&a), write(1, "OK\n", 3), 0);
	return (remove_list(&b), remove_list(&a), write(1, "KO\n", 3), 0);
}
