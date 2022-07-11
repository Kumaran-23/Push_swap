/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:55:21 by snair             #+#    #+#             */
/*   Updated: 2022/01/10 18:48:12 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_len(int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

void	ft_putnbr(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		len++;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	ft_printnbr(int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		ft_putnbr(num);
		return (ft_len(num) + 1);
	}
	else
		ft_putnbr(num);
	return (ft_len(num));
}
