
#include "push_swap.h"

// void f()
// {
//     system("leaks push_swap");
// }

void print_stack(t_stack **list)
{
    t_stack *temp;

    if (!list)
        return;
    temp = *list;
    printf("list : \n");
    while (temp)
    {
        // printf("id : %zu ", temp->index);
        printf(" [%ld] ", temp->num);
        printf(" id = [%d] ", temp->index);
        printf(" pos = [%d] ", temp->pos);
        printf(" target pos = [%d] ", temp->target_pos);
        printf(" cost = [%d]  ", temp->cost);
        printf(" target moves = [%d]  ", temp->target_moves);
        printf(" moves = [%d] \n", temp->moves);
        temp = temp->nxt;
    }
    printf("\n-------------------------------\n");
}

int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    // int value;
    int *arr;
    int i;
    // atexit(f);
    i = 1;
    a = NULL;
    b = NULL;
    arr = NULL;

        // printf("ac = %d\n", ac);
    while (i < ac )
        node_addback(&a, create_node(ft_atoi(av[i++]), -1));
    update_pos(&a);
    update_pos(&b);

    // printf("\n----- before : stack a -----\n\n");
    // print_stack(&a);

    push_swap(&a, &b);

    // printf("\n\n----- after : stack a -----\n\n");
    // print_stack(&a);
    // printf("\n\n----- after : stack b -----\n\n");
    // print_stack(&b);

    remove_list(&a);
    remove_list(&b);
    // free(arr);
}

// stopped here ----------------------------------------------------------
