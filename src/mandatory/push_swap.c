#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

int	sort_stack(t_stack *stack, int size)
{
	if (sorted(stack->a, stack->a_size, 0) == 0)
	{
		if (size == 2)
			sa(stack);
		else if (size == 3)
			quicksort_3(stack, size);
		else if (size <= 5)
			sort_5(stack, size);
		else
			quicksort_a(stack, size);
	}
	return (0);
}

void    init_stack(char **argv)
{
    t_stack     stack;
    int         size;
    int         i;

    i = -1;
    size = argv_strlen(argv);
    stack.a = malloc(sizeof(int) * size);
    stack.a_size = size;
    if(!stack.a)
        return ; 
    stack.b = malloc(sizeof(int) * size);
    stack.b_size = 0;
    while(++i < size)
        stack.a[i] = new_atoi(argv[i], stack.a);
    check_dup(stack.a, size);
	sort_stack(&stack, size);
	free(stack.a);
	free(stack.b);
}

int main(int argc, char **argv)
{

    if(argc > 1)
    {
        argv++;
        if(argc == 2)
            argv = ft_split(*argv, ' ');
        init_stack(argv);
		return(0);
    }
	return(0);
}