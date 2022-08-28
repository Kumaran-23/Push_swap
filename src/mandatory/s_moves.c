/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:08:38 by snair             #+#    #+#             */
/*   Updated: 2022/08/25 14:22:03 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void	s_helper(int *stack, int size)
{
	int	i;

	i = 1;
	if (size >= 2)
		swap(stack + i, stack + (i - 1));
}

void	sa(t_stack *stack)
{
	ft_printf("sa\n");
	s_helper(stack->a, stack->a_size);
}

void	sb(t_stack *stack)
{
	ft_printf("sb\n");
	s_helper(stack->b, stack->b_size);
}

void	ss(t_stack *stack)
{
	ft_printf("ss\n");
	s_helper(stack->b, stack->b_size);
	s_helper(stack->a, stack->a_size);
}
