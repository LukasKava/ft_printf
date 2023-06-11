/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:03:48 by lkavalia          #+#    #+#             */
/*   Updated: 2022/03/23 22:29:29 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*---- Function to write the character ----*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/*---- Print out the string ----*/

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*---- Printing out the digit using ft_itoa function ----*/

int	print_digit(int d)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(d);
	len += print_str(str);
	free(str);
	return (len);
}
