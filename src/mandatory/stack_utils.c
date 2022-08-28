/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:09:31 by snair             #+#    #+#             */
/*   Updated: 2022/08/27 18:43:20 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void	error(int *stack)
{
	free(stack);
	write(2, "Error", 5);
	write(2, "\n", 1);
	exit(1);
}

int	argv_strlen(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}

int	new_atoi(char *str, int *stack)
{
	long int	ret;
	int			sign;
	int			i;

	ret = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(stack);
		ret = ret * 10 + (str[i] - '0') * sign;
		i++;
	}
	if ((ret < -2147483648 || ret > 2147483647)
		|| str[i - 1] == '-' || str[i - 1] == '+')
		error(stack);
	return (ret);
}

int	sorted(int *stack, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i] < stack[i - 1])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	check_dup(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				error(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}
