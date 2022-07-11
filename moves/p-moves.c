#include <stdio.h>
#include <stdlib.h>
//#include "../inc/push_swap.h"

typedef struct p_stack
{
    int *a;
    int *b;
    int a_size;
    int b_size;
}       t_stack;

void    pa(t_stack *stack)
{
    if(stack->b_size > 0)
    {
        stack->a[stack->a_size++] = stack->b[stack->b_size--];
        printf("pa\n");
    }
    else
        printf("Stack b is empty, Nothing done\n");
}

void    pb(t_stack *stack)
{
    if(stack->a_size > 0)
    {
        stack->b[stack->b_size++] = stack->a[stack->a_size--];
        printf("pb\n");
    }
    else
        printf("Stack a is empty, Nothing done\n");
}
