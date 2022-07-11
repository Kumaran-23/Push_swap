/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:19:27 by snair             #+#    #+#             */
/*   Updated: 2022/01/08 16:04:13 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_formats(va_list arg, const char format);
int		ft_printf(const char *str, ...);
int		ft_printpercent(void);
int		ft_putchar(int c);
int		ft_ptrlen(unsigned long long num);
void	ft_putptr(unsigned long long num);
int		ft_printptr(unsigned long long ptr);
int		ft_hexlen(unsigned int num);
void	ft_puthex(unsigned int num, const char format);
int		ft_printhex(unsigned int num, const char format);
int		ft_printnbr(int n);
void	ft_putnbr(long nbr);
int		ft_len(int num);
int		ft_uprintnbr(unsigned int n);
void	ft_uputnbr(unsigned long n);
int		ft_ulen(unsigned int nbr);
int		ft_putstr_fd(char *s, int fd);

#endif
