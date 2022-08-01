#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void	pivot_sort(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] > stack[j])
				swap(stack + i, stack + j);
			j++;
		}
		i++;
	}
}

int	get_pivot(int *pivot, int *stack, int size)
{
	int		*temp;
	int		i;

	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return (0);
	i = 0;
	while (i < size)
	{
		temp[i] = stack[i];
		i++;
	}
	pivot_sort(temp, size);
	*pivot = temp[size / 2];
	free(temp);
	return (1);
}

void	sort_3a(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s);
		rra(s);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s);
		ra(s);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s);
}

int		quicksort_3(t_stack *stack, int len)
{
	if (len == 3 && stack->a_size == 3)
		sort_3a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	else
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
					&& stack->a[1] < stack->a[2]))
		{
			if (stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack);
			else if (!(stack->a[2] > stack->a[0] 
				&& stack->a[2] > stack->a[1]) && len--)
				pb(stack);
			else if (len++)
				pa(stack);
		}
	}
	return (1);
}

int		quicksort_3b(t_stack *stack, int len)
{
	if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack);
		while (len--)
			pa(stack);
	}
	else if (len == 3)
	{
		while (len)
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				sa(stack);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1]))
			{
				pa(stack);
				len--;
			}
			else
				sb(stack);
		}
	}
	return (1);
}