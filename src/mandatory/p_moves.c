/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:06:18 by snair             #+#    #+#             */
/*   Updated: 2022/08/25 14:21:09 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void	p_helper(int *stack, int size)
{
	int	i;

	if (size < 1)
		return ;
	i = size;
	while (i > 0)
	{
		swap(stack + i, stack + (i - 1));
		i--;
	}
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		stack->b_size++;
		p_helper(stack->b, stack->b_size);
		stack->b[0] = stack->a[0];
		i = 0;
		stack->a_size--;
		while (i < stack->a_size)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		ft_printf("pb\n");
	}
}

void	pa(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		stack->a_size++;
		p_helper(stack->a, stack->a_size);
		stack->a[0] = stack->b[0];
		i = 0;
		stack->b_size--;
		while (i < stack->b_size)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		ft_printf("pa\n");
	}
}
