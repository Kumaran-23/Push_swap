#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include "libft.h"
#include <limits.h>

typedef struct p_stack
{
    int *a;
    int *b;
    int a_size;
    int b_size;
}       t_stack;

//push_swap initializing stack and main function
void    init_stack(char **argv);
//moves to perform
void    pa(t_stack *stack);
void    pb(t_stack *stack);
#endif 