/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:32:21 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/19 16:57:42 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_lst
{
   long num;
   int index;
   int pos;
   int target_pos;
   int cost;
   int moves;
   int target_moves;
   struct s_lst *prv;
   struct s_lst *nxt;
} t_stack;

typedef struct s_var
{
   int *numbers;
   int *indexes;
   int *length;
   int *sub;
   int pivot;
   int len;
   int LIS_len;
   int i;
   int j;
   int highest;
} t_var;




t_stack *create_node(long value, size_t index);
int node_addfront(t_stack **list, t_stack *new);
int node_addback(t_stack **list, t_stack *new);
int delete_node(t_stack *node);
void remove_list(t_stack **list);
int list_len(t_stack **list);

void push_to_stack(t_stack **push_to, t_stack **from);
void rotate_stack(t_stack **a);
void rotate_both(t_stack **b, t_stack **a);
void rev_rot_stack(t_stack **stack);
void rev_rot_both(t_stack **b, t_stack **a);
void swap_elements(t_stack **stack);
void swap_both(t_stack **a, t_stack **b);

void update_indexes(t_stack **stack, t_var *var);
void fill_numbers(t_stack **stack, int *numbers);
void fill_indexes(t_stack **stack, int *indexes);
int init_variables(t_stack **stack , t_var *var);
void bubble_sort(t_var *var);
void sort_three(t_stack **stack);

int  push_swap(t_stack **a, t_stack **b);
void update_pos(t_stack **stack);


void update_cost(t_stack **a , t_stack **b);
void execute_moves(t_stack **a , t_stack **b);


void print_stack(t_stack **list);
int	ft_atoi(const char *str);


// int *lis_algo(t_stack **stack);
// int *lis_algo(t_LIS *var);
int find_highest(int *arr, size_t size);
int *get_LIS(t_var *var);
int *lis_algo(t_var *var);
int is_in_LIS(t_stack *stack, t_var *var, int *LIS);

#endif