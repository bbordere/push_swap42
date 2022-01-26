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

CC = clang

CFLAGS = -Wall -Wextra -Werror

FILES = main.c operations.c operations2.c parse_args.c presort.c \
		sorter_utils.c stack.c simple_sort.c algo.c utils.c mark_utils.c stack_utils.c

SRCS = $(addprefix src/, $(FILES))

OBJS = $(SRCS:.c=.o)

NAME = push_swap

$(NAME): $(OBJS)
		
	@ printf '\033[0;33mCompiling Libft\033[0m\n'
	@ $(MAKE) -s all -C libft
	@ printf '\033[0;32mLibft compiled sucessfully !\033[0m\n'
	@ printf '\033[0;33mCompiling push_swap\033[0m\n'
	@ ${CC} ${CFLAGS} $(OBJS) libft/libft.a -o ${NAME} 
	@ printf '\033[0;32mpush_swap compiled sucessfully !\033[0m\n'

all: $(NAME)

clean:
	@ rm -f $(OBJS)
	@ $(MAKE) -s clean -C libft
	@ $(MAKE) -s clean -C src/checker
	@ printf '\033[0;32mclean done\033[0m\n'

fclean: clean
	@ rm -f ${NAME}
	@ rm -f checker
	@ $(MAKE) -s fclean -C libft
	@ $(MAKE) -s fclean -C src/checker
	@ printf '\033[0;32mfclean done\033[0m\n'

bonus:
	@ $(MAKE) -s all -C src/checker

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJS)
