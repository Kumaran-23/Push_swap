#include <stdio.h>
#include <stdlib.h>

typedef struct p_stack
{
    int *a;
    int *b;
    int a_size;
    int b_size;
}       t_stack;

void    init_stack(char **argv)
{
    t_stack     stack;
    int         size;
    int         i;

    i = -1;
    size = argv_strlen(argv);
    stack.a = (int *)malloc(sizeof(int) * size);
    stack.a_size = size;
    if(!stack.a)
        return ; 
    stack.b = (int *)malloc(sizeof(int) * size);
    stack.b_size = 0;
    if(!stack.b)
    {
        free(stack.a);
        return ;
    }
    while(++i < size)
        stack.a[i] = new_atoi(argv[i], stack.a);
    check_dup(stack.a, size);
}

int main(int argc, char **argv)
{
	if(argc > 1)
    {
        argv++;
        if(argc == 2)
            argv = ft_split(*argv, ' ');
        init_stack(argv);
    }
}