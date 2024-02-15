/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:32:21 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/15 16:52:08 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_lst
{
   long num;
   int index;
   struct s_lst *prv;
   struct s_lst *nxt;
} t_stack;

typedef struct s_LIS
{
   int *numbers;
   int *length;
   int *sub;
   int i;
   int j;
   int highest;
   int len;
} t_LIS;

t_stack *create_node(long value, size_t index);
int node_addfront(t_stack **list, t_stack *new);
int node_addback(t_stack **list, t_stack *new);
int delete_node(t_stack *node);
void remove_list(t_stack **list);
size_t list_len(t_stack **list);
void update_indexes(t_stack **stack);
void push_to_stack(t_stack **push_to, t_stack **from);
void rotate_stack(t_stack **a);
void rotate_both(t_stack **b, t_stack **a);
void rev_rot_stack(t_stack **stack);
void rev_rot_both(t_stack **b, t_stack **a);
void swap_elements(t_stack **stack);
void swap_both(t_stack **a, t_stack **b);


int *lis_algo(t_stack **stack);

#endif