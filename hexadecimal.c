/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:39:41 by lkavalia          #+#    #+#             */
/*   Updated: 2022/03/24 17:32:16 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*---- Printing out the hexadecimal digit ----*/

static int	hex_len(unsigned long hx)
{
	int	i;

	i = 0;
	while (hx != 0)
	{
		hx = hx / 16;
		i++;
	}
	return (i);
}

static int	write_hex(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
	free(str);
	return (len);
}

int	print_hex(unsigned long hx, const char format)
{
	int		len;
	char	*s;
	int		r;

	len = hex_len(hx);
	r = 0;
	if (hx == 0)
		return (print_char('0'));
	s = malloc(sizeof(char) * len + 1);
	s[len] = '\0';
	len--;
	while (hx != 0)
	{
		r = hx % 16;
		if (r < 10)
			s[len] = 48 + r;
		if (r > 9 && format == 'x')
			s[len] = 97 + (r - 10);
		if (r > 9 && format == 'X')
			s[len] = 65 + (r - 10);
		hx = hx / 16;
		len--;
	}
	len = write_hex(s);
	return (len);
}
