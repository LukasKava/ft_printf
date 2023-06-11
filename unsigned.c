/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:56:28 by lkavalia          #+#    #+#             */
/*   Updated: 2022/03/23 14:11:47 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*---- Printing an unsigned integer ----*/

static unsigned int	calculate(int d)
{
	unsigned int	answer;
	int				i;

	answer = 2;
	i = 0;
	while (i != 32)
	{
		answer = answer * 2;
		i++;
	}
	answer += d;
	return (answer);
}

unsigned int	print_unsigned_i(int d)
{
	unsigned int	answer;
	char			*str;
	int				len;

	answer = 0;
	len = 0;
	if (d < 0)
		answer = calculate(d);
	else
		answer = d;
	str = ft_u_itoa(answer);
	len += print_str(str);
	free(str);
	return (len);
}
