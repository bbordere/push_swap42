CC = clang

CFLAGS = -Wall -Wextra -Werror

FILES = checker.c ../stack_utils.c ../stack.c ../operations2.c ../operations.c ../parse_args.c ../presort.c

OBJS = $(FILES:.c=.o)

NAME = checker

$(NAME): $(OBJS)
	@ $(MAKE) -s all -C ../../libft
	@ printf '\033[0;33mCompiling checker\033[0m\n'
	@ ${CC} ${CFLAGS} $(OBJS) ../../libft/libft.a -o ${NAME}
	@ cp checker ../../checker
	@ printf '\033[0;32mchecker compiled sucessfully !\033[0m\n'

all: $(NAME)

clean:
	@ rm -f $(OBJS)
	@ $(MAKE) -s clean -C ../../libft

fclean: clean
	@ rm -f ${NAME}
	@ $(MAKE) -s fclean -C ../../libft