/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:08:12 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/18 18:33:37 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// init variables

void fill_numbers(t_stack **stack, int *numbers)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        numbers[i++] = tmp->num;
        tmp->index = -1;
        tmp = tmp->nxt;
    }
}

void fill_indexes(t_stack **stack, int *indexes)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        indexes[i++] = tmp->index;
        tmp = tmp->nxt;
    }
}

// int init_variables(t_stack **stack, t_var *var)
// {
//     var->len = list_len(stack);
//     if (!stack || !var->len)
//         return 1;
//     var->numbers = malloc(var->len * sizeof(int));
//     if (!var->numbers)
//         return 1;
//     fill_numbers(stack, var->numbers);
//     return 0;
// }

// bubblesort func

void bubble_sort(t_var *var)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < var->len - 1)
    {
        j = 0;
        while (j < var->len - i - 1)
        {
            if (var->numbers[j] > var->numbers[j + 1])
            {
                temp = var->numbers[j];
                var->numbers[j] = var->numbers[j + 1];
                var->numbers[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

// update indexes func

void update_indexes(t_stack **stack, t_var *var)
{
    int i;
    t_stack *tmp;

    tmp = *stack;
    bubble_sort(var);
    if (!stack)
        return;
    while (tmp)
    {
        i = 0;
        while (i < var->len)
        {
            if (tmp->num == var->numbers[i])
            {
                tmp->index = i;
                break;
            }
            else
                i++;
        }
        tmp = tmp->nxt;
    }
    fill_indexes(stack, var->indexes);
}

void sort_three(t_stack **stack)
{
    int first;
    int middle;
    int last;

    first = (*stack)->index;
    middle = (*stack)->nxt->index;
    last = (*stack)->nxt->nxt->index;
    if (first < last && first > middle)
        swap_elements(stack);
    else if (first > last && middle > last)
    {
        swap_elements(stack);
        rev_rot_stack(stack);
    }
    else if (first > last && middle < last)
        rotate_stack(stack);
    else if (first < middle && first < last)
    {
        swap_elements(stack);
        rotate_stack(stack);
    }
    else if (first < middle && middle > last)
        rev_rot_stack(stack);
    else 
        printf("already sorted\n");
}

