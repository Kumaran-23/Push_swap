/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:08:02 by snair             #+#    #+#             */
/*   Updated: 2022/08/25 14:08:07 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	r_helper(int *stack, int size)
{
	int	i;

	if (size < 1)
		return ;
	i = 1;
	while (i < size)
	{
		swap(stack + i, stack + (i - 1));
		i++;
	}
}

void	rb(t_stack *stack)
{
	ft_printf("rb\n");
	r_helper(stack->b, stack->b_size);
}

void	ra(t_stack *stack)
{
	ft_printf("ra\n");
	r_helper(stack->a, stack->a_size);
}

void	rr(t_stack *stack)
{
	ft_printf("rr\n");
	r_helper(stack->a, stack->a_size);
	r_helper(stack->b, stack->b_size);
}
