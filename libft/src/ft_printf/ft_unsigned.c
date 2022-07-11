/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:55:21 by snair             #+#    #+#             */
/*   Updated: 2022/01/10 18:48:40 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulen(unsigned int num)
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

void	ft_uputnbr(unsigned long nbr)
{
	if (nbr >= 10)
	{
		ft_uputnbr(nbr / 10);
		ft_uputnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	ft_uprintnbr(unsigned int num)
{
	if (num == 0)
		return (ft_putchar('0'));
	else
		ft_uputnbr(num);
	return (ft_ulen(num));
}
