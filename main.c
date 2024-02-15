
#include "push_swap.h"

// void f()
// {
//     system("leaks push_swap");
// }
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
void fill_numbers(t_stack **stack, int *numbers)
{
    t_stack *tmp;
    int i;

    i = 0;

    tmp = *stack;
    while (tmp)
    {
        numbers[i++] = tmp->num;
        tmp = tmp->nxt;
    }
}
int init_variables(t_stack **stack, t_LIS *var)
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
    fill_numbers(stack, var->numbers);
    var->i = 0;
    while (var->i < var->len)
        var->length[var->i++] = 1;
    var->i = 1;
    var->sub[0] = 0;
    var->j = 0;
    return 0;
}

int *get_LIS(t_LIS *var) // returns LIS members indexes in stack
{
    int *LIS;

    LIS = malloc(var->length[var->highest] * sizeof(int));
    if (!LIS)
        return free(var->length), free(var->sub), free(var->numbers), NULL;
    var->i = var->highest;
    var->j = var->length[var->highest];
    while (var->j)
    {
        LIS[--(var->j)] = var->i;
        var->i = var->sub[var->i];
    }
    return LIS;
}

int *lis_algo(t_stack **stack)
{
    t_LIS var;
    int *LIS;

    if (init_variables(stack, &var))
        return NULL;
    while (var.i < var.len)
    {
        while (var.j < var.i)
        {
            if (var.numbers[var.j] < var.numbers[var.i] && var.length[var.j] + 1 >= var.length[var.i])
            {
                var.length[var.i] = var.length[var.j] + 1;
                var.sub[var.i] = var.j;
            }
            var.j++;
        }
        var.i++;
        var.j = 0;
    }
    var.highest = find_highest(var.length, var.len);
    LIS = get_LIS(&var);
    return free(var.length), free(var.sub), free(var.numbers), LIS;
}

static void print_stack(t_stack **list)
{
    t_stack *temp;

    temp = *list;
    printf("list : ");
    while (temp)
    {
        // printf("id : %zu ", temp->index);
        printf(" [%ld] ", temp->num);
        temp = temp->nxt;
    }
    printf("\n-------------------------------\n");
}
static int is_in_LIS(t_stack *stack, int *LIS)
{
    int i;

    i = 0;
    while (i < 6) // LIS len
    {
        if (stack->index == LIS[i++])
            return 1;
    }
    return 0;
}

void move_nonLIS_to_b(t_stack **a, t_stack **b, int *LIS)
{
    t_stack *tmp;
    t_stack *next_tmp;

    tmp = *a;
    while (tmp)
    {
        next_tmp = tmp->nxt;
        if (!is_in_LIS(tmp, LIS))
        {
            if (tmp->prv)
                tmp->prv->nxt = tmp->nxt;
            if (tmp->nxt)
                tmp->nxt->prv = tmp->prv;
            tmp->nxt = NULL;
            tmp->prv = NULL;
            node_addback(b, tmp);
        }
        else
            tmp = tmp->nxt;
        tmp = next_tmp;
    }
    update_indexes(a);
    update_indexes(b);
}
//  Result: DONE!
// list :  [10]  [15]  [13]  [9]  [21]  [22]  [35]  [29]  [64]
// a must be : [10]  [13]  [21]  [22]  [29]  [64]
// b must be : [15] [9]  [35]
int main()
{
    t_stack *a;
    t_stack *b;
    int value;
    int *arr;
    size_t i;
    // atexit(f);
    value = 1;
    i = 0;
    a = NULL;
    b = NULL;
    arr = NULL;
    // node_addback(&a, create_node(10, i++));
    // node_addback(&a, create_node(15, i++));
    // node_addback(&a, create_node(13, i++));
    // node_addback(&a, create_node(9, i++));
    // node_addback(&a, create_node(21, i++));
    // node_addback(&a, create_node(22, i++));
    // node_addback(&a, create_node(35, i++));
    // node_addback(&a, create_node(29, i++));
    // node_addback(&a, create_node(64, i++));

    //  10 15 21 22 35

    node_addback(&a, create_node(0, i++));
    node_addback(&a, create_node(4, i++));
    node_addback(&a, create_node(12, i++));
    node_addback(&a, create_node(2, i++));
    node_addback(&a, create_node(10, i++));
    node_addback(&a, create_node(6, i++));
    node_addback(&a, create_node(9, i++));
    node_addback(&a, create_node(13, i++));
    node_addback(&a, create_node(3, i++));
    node_addback(&a, create_node(11, i++));
    node_addback(&a, create_node(7, i++));
    node_addback(&a, create_node(15, i++));  //  0 2 6 9 11 15
    // i = 0;
    // while (value <= 12)
    //     node_addback(&b, create_node(value++, i++));
    printf("\n----- before : stack a -----\n\n");
    print_stack(&a);
    // printf("len a: %zu\n", list_len(&a));

    arr = lis_algo(&a);
    i = 0;
    printf("\n----- LIS : stack a -----\n\n");
    while (i < 6)
        printf("[%d] ", arr[i++]);
    move_nonLIS_to_b(&a, &b, arr);
    // printf("\n----- before : stack b -----\n\n");
    // print_stack(&b);
    // printf("len b: %zu\n", list_len(&b));
    // //---------------//move//--------------//
    // swap_both(&a, &b);
    // //-------------------------------------//
    printf("\n----- after : stack a -----\n\n");
    print_stack(&a);
    // printf("len a: %zu\n", list_len(&a));

    printf("\n----- after : stack b -----\n\n");
    print_stack(&b);
    // printf("len b: %zu\n", list_len(&b));
    //     rev_rot_stack(&a);
    //     rev_rot_stack(&b);
    //     printf("\n----- after 2 : stack a -----\n\n");
    //     print_stack(&a);
    //     printf("\n----- after 2 : stack b -----\n\n");
    //     print_stack(&b);
    // remove_list(&a);
    // remove_list(&b);
    // free(arr);
}

// stopped here ----------------------------------------------------------
