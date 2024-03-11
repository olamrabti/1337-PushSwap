/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:09:43 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/11 14:12:54 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 50

typedef struct s_parse
{
	int		i;
	int		j;
	int		k;
	int		checker;
	char	**sp;
}	t_parse;

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

char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *s1, void *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_updatestock(char *str, size_t i);
char	*ft_fill_stock(int fd, char *stock);
char	*ft_getline(char *stock);
void	ft_free_gnl(char *str);
int		ft_strchrnl(char *str);

int		ft_atoi(const char *str, int *checker);

char	**ft_free(char **copy, size_t j);
char	**ft_split(char const *s, char c);
void	read_input(char **store);

t_stack	*create_node(long value, size_t index);
int		node_addfront(t_stack **list, t_stack *new);
int		node_addback(t_stack **list, t_stack *new);
int		delete_node(t_stack *node);
void	remove_list(t_stack **list);

size_t	ft_strlen(const char *str);
int		check_args(t_parse *pv, t_stack **a);
int		parse_args(int ac, char *av[], t_stack **a);
int		check_doubles(t_stack **stack);
int		is_sorted(t_stack **stack);

int		list_len(t_stack **list);
void	push_to_stack(t_stack **push_to, t_stack **from, char *print);

void	rev_rot_stack(t_stack **stack, char *print);
void	rev_rot_both(t_stack **b, t_stack **a, char *print);	
void	rotate_stack(t_stack **stack, char *print);
void	rotate_both(t_stack **b, t_stack **a, char *print);	
void	swap_elements(t_stack **stack, char *print);
void	swap_both(t_stack **a, t_stack **b, char *print);

#endif
