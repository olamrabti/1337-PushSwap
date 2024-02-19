/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:12 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/19 17:50:28 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_highest(int *arr, size_t size)
{
    int highest;

    highest = size;
    while (size)
    {
        if (arr[highest] < arr[size])
            highest = size;
        size--;
    }
    return highest;
}

int init_variables(t_stack **stack, t_var *var)
{

    var->len = list_len(stack);
    if (!stack || !var->len)
        return 1;
    var->length = malloc(var->len * sizeof(int));
    if (!var->length)
        return 1;
    var->sub = malloc(var->len * sizeof(int));
    if (!var->sub)
        return free(var->length), 1;
    var->numbers = malloc(var->len * sizeof(int));
    if (!var->numbers)
        return free(var->length), free(var->sub), 1;
    var->indexes = malloc(var->len * sizeof(int));
    if (!var->indexes)
        return free(var->length), free(var->sub),free(var->numbers), 1;
    fill_numbers(stack, var->numbers);
    var->i = 0;
    while (var->i < var->len)
        var->length[var->i++] = 1;
    var->i = 1;
    var->sub[0] = 0;
    var->j = 0;
    return 0;
}

int *get_LIS(t_var *var) // returns LIS members indexes in stack
{
    int *LIS;
    var->LIS_len = var->length[var->highest];
    LIS = malloc(var->LIS_len * sizeof(int));
    if (!LIS)
        return free(var->length), free(var->sub), free(var->indexes), NULL;
    var->i = var->highest;
    var->j = var->LIS_len;
    while (var->j)
    {
        LIS[--(var->j)] = var->indexes[var->i];
        var->i = var->sub[var->i];
    }
    return LIS;
}

int *lis_algo(t_var *var)
{
    int *LIS;

    while (var->i < var->len)
    {
        while (var->j < var->i)
        {
            if (var->indexes[var->j] < var->indexes[var->i] && var->length[var->j] + 1 >= var->length[var->i])
            {
                var->length[var->i] = var->length[var->j] + 1;
                var->sub[var->i] = var->j;
            }
            var->j++;
        }
        var->i++;
        var->j = 0;
    }
    var->highest = find_highest(var->length, var->len);
    LIS = get_LIS(var);
    return free(var->length), free(var->sub), free(var->indexes), LIS;
}

int is_in_LIS(t_stack *stack, t_var *var, int *LIS)
{
    int i;

    i = 0;
    while (i < var->LIS_len)
    {
        if (stack->index == LIS[i++])
            return 1;
    }
    return 0;
}
