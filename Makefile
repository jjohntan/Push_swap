NAME = push_swap

SRCS = src/push_swap.c \
       src/error_free.c \
       src/push_swap_init.c \
       src/stack_init.c \
	   src/stack_utils.c

UTILS = src/utils/push.c \
		src/utils/reverse_rotate.c \
		src/utils/rotate.c \
		src/utils/swap.c \
		src/utils/sort_stacks.c \
		src/utils/sort_three.c

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft $(FSANTIZE)
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
