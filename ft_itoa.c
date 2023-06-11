/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:44:37 by lkavalia          #+#    #+#             */
/*   Updated: 2022/03/22 16:53:04 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*---- Libft Functions ----*/
/*---- ft_itoa.c to convert the number to the string ----*/

static size_t	i_counter(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	b;
	char	*conv;

	len = i_counter(n);
	conv = malloc(sizeof(char) * (len + 1));
	if (!conv)
		return (NULL);
	conv[len] = '\0';
	if (n < 0)
	{
		conv[0] = '-';
		b = 1;
	}
	else
		b = 0;
	while (len-- > b)
	{
		if (n < 0)
			conv[len] = '0' + n % 10 * (-1);
		else
			conv[len] = '0' + n % 10;
		n = n / 10;
	}
	return (conv);
}

/*---- Adjusted ft_itoa.c for unsigned int ----*/

static size_t	u_i_counter(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_u_itoa(unsigned int n)
{
	size_t	len;
	size_t	b;
	char	*conv;

	len = u_i_counter(n);
	conv = malloc(sizeof(char) * (len + 1));
	if (!conv)
		return (NULL);
	conv[len] = '\0';
	b = 0;
	while (len-- > b)
	{
		conv[len] = '0' + n % 10;
		n = n / 10;
	}
	return (conv);
}
