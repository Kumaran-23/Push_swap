#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

int     get_min(int *stack, int len)
{
        int     temp;
        int     i;

        i = 0;
        temp = stack[i];
        while (len--)
        {
                if (temp > stack[i])
                        temp = stack[i];
                i++;
        }
        return (temp);
}

void	rotate_5(t_stack *stack, int len)
{
	int i;
	int min;

	min = get_min(stack->a, len);
	i = 0;
	while (stack->a[i] != min)
		i++;
	if (i < len / 2 + len % 2)
		ra(stack);
		
	else
		rra(stack);
}

int	sort_5(t_stack *stack, int len)
{
	int i;
	i = 0;

	if (len <=3)
		return (quicksort_3(stack, len));
	while(len != 3)
	{
		if (stack->a[0] == get_min(stack->a, len) && len--)
			pb(stack);
		rotate_5(stack, len);
		i++;
	}
	while (i < 8)
	{
		quicksort_3(stack, len);
		i++;
	}
	while (i++ < 10 && len++)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack);
		pa(stack);
	}
	return (1);
}


/*-pivot gets initialized in get_pivot function
  -len/2 + len % 2 is to account for odd number
  -if first element less than pivot push to b
  -if not ra till first element less than pivot
  -count keeps track of how many times times ra are made 
  -minus when rra is done*/

int	quicksort_a(t_stack *stack, int len)
{
	int	pivot;
	int	size;
	int	count;

	if (sorted(stack->a, len, 0) == 1)
		return (1);
	size = len;
	count = 0;
	if (!get_pivot(&pivot, stack->a, len))
		return (0);
	if (len <= 3)
		return (quicksort_3(stack, len));
	while (len != size / 2 + size % 2)
	{
		if (stack->a[0] < pivot && len--)
			pb(stack);
		else if (++count)
			ra(stack);
	}
	while (count--)
		rra(stack);
	return (quicksort_a(stack, size / 2 + size % 2)
		&& quicksort_b(stack, size / 2));
}

int	quicksort_b(t_stack *stack, int len)
{
	int	pivot;
	int	size;
	int	count;

	if (sorted(stack->b, len, 1) == 1)
		while (len--)
			pa(stack);
	if (len <= 3)
		return (quicksort_3b(stack, len));
	size = len;
	count = 0;
	if (!get_pivot(&pivot, stack->b, len))
		return (0);
	while (len != size / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack);
		else if (++count)
			rb(stack);
	}
	while (count--)
		rrb(stack);
	return (quicksort_a(stack, size / 2 + size % 2)
		&& quicksort_b(stack, size / 2));
}