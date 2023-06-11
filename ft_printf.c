/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:19:29 by lkavalia          #+#    #+#             */
/*   Updated: 2022/03/24 17:57:19 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*---- The conversion character function ----*/

int	formatting(char format, va_list arg)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += print_char(va_arg(arg, int));
	if (format == 's')
		len += print_str(va_arg(arg, char *));
	if (format == 'd' || format == 'i')
		len += print_digit(va_arg(arg, int));
	if (format == 'u')
		len += print_unsigned_i(va_arg(arg, unsigned int));
	if (format == 'x' || format == 'X')
		len += print_hex(va_arg(arg, unsigned int), format);
	if (format == 'p')
		len += print_ptr(va_arg(arg, unsigned long));
	if (format == '%')
	{
		ft_putchar_fd('%', 1);
		len += 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		answer;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	answer = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			answer += formatting(format[i + 1], arg);
			i++;
		}
		else
			answer += write (1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (answer);
}
