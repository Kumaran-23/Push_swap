/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:08:15 by snair             #+#    #+#             */
/*   Updated: 2022/08/25 14:08:19 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void	rr_helper(int *stack, int size)
{
	int	i;

	if (size < 1)
		return ;
	i = size - 1;
	while (i > 0)
	{
		swap(stack + i, stack + (i - 1));
		i--;
	}
}

void	rrb(t_stack *stack)
{
	ft_printf("rrb\n");
	rr_helper(stack->b, stack->b_size);
}

void	rra(t_stack *stack)
{
	ft_printf("rra\n");
	rr_helper(stack->a, stack->a_size);
}

void	rrr(t_stack *stack)
{
	ft_printf("rrr\n");
	rr_helper(stack->a, stack->a_size);
	rr_helper(stack->b, stack->b_size);
}
