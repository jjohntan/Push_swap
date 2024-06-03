NAME = push_swap

NAME_BONUS = checker

SRCS = src/push_swap.c \
       src/error_free.c \
       src/stack_init.c \
	   src/stack_utils.c \
	   src/stack_utils2.c

UTILS = src/utils/push.c \
		src/utils/reverse_rotate.c \
		src/utils/rotate.c \
		src/utils/swap.c \
		src/utils/sort_small_stack.c \
		src/utils/sort_big_stack.c
		
BONUS = checker/checker.c \
		checker/error_free_bonus.c \
		checker/get_next_line.c \
		checker/get_next_line_utils.c \
		checker/push_bonus.c \
		checker/reverse_rotate_bonus.c \
		checker/rotate_bonus.c \
		checker/stack_init_bonus.c \
		checker/stack_utils_bonus.c \
		checker/swap_bonus.c

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	
bonus: $(BONUS_OBJS) libft
	$(CC) $(CFLAGS) $(BONUS_OBJS) -Llibft -lft -o $(NAME_BONUS)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


libft:
	make -C libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
