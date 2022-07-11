/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:58:37 by snair             #+#    #+#             */
/*   Updated: 2022/01/08 16:15:25 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_formats(va_list arg, const char format)
{
	int	printlen;

	printlen = 0;
	if (format == 'c')
		printlen += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		printlen += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (format == 'p')
		printlen += ft_printptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		printlen += ft_printnbr(va_arg(arg, int));
	else if (format == 'u')
		printlen += ft_uprintnbr(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		printlen += ft_printhex(va_arg(arg, unsigned int), format);
	else if (format == '%')
		printlen += ft_printpercent();
	return (printlen);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		printlen;

	i = 0;
	printlen = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printlen += ft_formats(arg, str[i + 1]);
			i++;
		}
		else
			printlen += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (printlen);
}
