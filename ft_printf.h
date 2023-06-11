/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:19:47 by lkavalia          #+#    #+#             */
/*   Updated: 2022/03/24 17:31:52 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*----Headers----*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*----Function prototypes----*/

int					print_char(int c);
void				ft_putchar_fd(char c, int fd);
int					print_str(char *str);
int					print_digit(int d);
char				*ft_itoa(int n);
char				*ft_u_itoa(unsigned int n);
unsigned int		print_unsigned_i(int d);
int					print_hex(unsigned long hx, const char format);
int					print_ptr(unsigned long ptr);
int					ft_printf(const char *format, ...);

#endif