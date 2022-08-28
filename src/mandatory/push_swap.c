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

void    leakfix(int *a, int *b, int size)
 {
    if (size != 12 && size != 8 && size != 4)
    {
        free(a);
        free(b);
    }
	if(size == 8 || size == 4)
		free(a);
 }

void    init_stack(char **argv)
{
    t_stack 	stack;
	int			size;
	int			i;

	i = -1;
	size = argv_strlen(argv);
	stack.a = (int *)malloc(size * sizeof(int));
	stack.a_size = size;
	stack.b = (int *)malloc(size * sizeof(int));
	stack.b_size = 0;
	while (++i < size)
		stack.a[i] = new_atoi(argv[i], stack.a);
	check_dup(stack.a, size);
	sort_stack(&stack, size);
    leakfix(stack.a, stack.b, size);
}

static void	free_char(char **argv)
{
	char	**pos;

	if (argv == NULL)
		return ;
	pos = argv;
	while (*pos)
		free(*(pos++));
	free(argv);
}

int main(int argc, char **argv)
{

    if(argc > 1)
    {
        argv++;
        if(argc == 2)
            argv = ft_split(*argv, ' ');
        init_stack(argv);
		if (argc == 2)
			free_char(argv);
		return(0);
    }
	return(0);
}
