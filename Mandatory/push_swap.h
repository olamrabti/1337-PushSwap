/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:32:21 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/11 14:15:06 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_lst
{
	long			num;
	int				index;
	int				pos;
	int				target_pos;
	int				cost;
	int				moves;
	int				target_moves;
	struct s_lst	*prv;
	struct s_lst	*nxt;
}	t_stack;

typedef struct s_var
{
	int	*numbers;
	int	*indexes;
	int	*size;
	int	*sub;
	int	pivot;
	int	len;
	int	lsub_len;
	int	i;
	int	j;
	int	highest;
}	t_var;

typedef struct s_moves
{
	int	cheapest;
	int	a_moves;
	int	b_moves;
}	t_moves;

typedef struct s_parse
{
	int		i;
	int		j;
	int		k;
	int		checker;
	char	**sp;
}	t_parse;

void	remove_list(t_stack **list);
t_stack	*create_node(long value, size_t index);
int		node_addfront(t_stack **list, t_stack *new);
int		node_addback(t_stack **list, t_stack *new);
int		delete_node(t_stack *node);

void	update_cost(t_stack **a, t_stack **b);
void	update_cheapest(t_stack **stack, t_moves *current);
void	execute_both(t_stack **a, t_stack **b, t_moves *current);
void	execute_separately(t_stack **a, t_stack **b, t_moves *current);
void	execute_moves(t_stack **a, t_stack **b);

int		ft_atoi(const char *str, int *checker);

char	**ft_split(char const *s, char c);
char	**ft_free(char **copy, size_t j);

int		*get_lsub(t_var *var);
int		*lsub_algo(t_var *var);
int		find_highest(int *arr, size_t size);
int		init_variables(t_stack **stack, t_var *var);
int		is_in_lsub(t_stack *stack, t_var *var, int *lsub);

size_t	ft_strlen(const char *str);
int		check_args(t_parse *pv, t_stack **a);
int		parse_args(int ac, char *av[], t_stack **a);
int		check_doubles(t_stack **stack);
int		is_sorted(t_stack **stack);

int		push_swap(t_stack **a, t_stack **b);

int		list_len(t_stack **list);
void	free_var(t_var *var);
void	rearrange_a(t_stack **a, int i);
void	from_a_to_b(t_stack **a, t_stack **b, t_var *var);
void	sort_five(t_stack **a, t_stack **b);

void	push_to_stack(t_stack **push_to, t_stack **from, char *print);

void	rev_rot_stack(t_stack **stack, char *print);
void	rev_rot_both(t_stack **b, t_stack **a, char *print);

void	rotate_stack(t_stack **stack, char *print);
void	rotate_both(t_stack **b, t_stack **a, char *print);

void	fill_numbers(t_stack **stack, int *numbers);
void	fill_indexes(t_stack **stack, int *indexes);
void	bubble_sort(t_var *var);
void	update_indexes(t_stack **stack, t_var *var);
void	sort_three(t_stack **stack);

void	swap_elements(t_stack **stack, char *print);
void	swap_both(t_stack **a, t_stack **b, char *print);

void	update_pos(t_stack **stack);
void	update_moves(t_stack **stack);
void	find_closest_bigger(t_stack **a, t_stack *tmp_b);
void	find_smallest_index(t_stack **a, t_stack *tmp_b);
void	update_target_pos(t_stack **a, t_stack **b);

#endif