# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 20:20:18 by lkavalia          #+#    #+#              #
#    Updated: 2022/03/23 14:57:57 by lkavalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_itoa.c ft_printf.c hexadecimal.c pointer.c random.c unsigned.c \

OBJ = $(SRC:.c=.o)

HEAD = ft_printf.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) $(HEAD)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) *.gch *.out

fclean: clean
	rm -f $(NAME)

re: fclean all