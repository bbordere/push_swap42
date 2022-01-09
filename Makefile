# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 14:57:02 by bbordere          #+#    #+#              #
#    Updated: 2022/01/06 11:43:55 by bbordere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard src/*.c)

OBJS = ${SRCS:.c=.o}

NAME = push_swap

${NAME}: ${OBJS}
		$(MAKE) all -C libft
		${CC} ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C libft

fclean: clean
		rm -f ${NAME}
		$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
