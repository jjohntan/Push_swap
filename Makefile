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
		
BONUS = bonus/checker.c \
		bonus/error_free_bonus.c \
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \
		bonus/push_bonus.c \
		bonus/reverse_rotate_bonus.c \
		bonus/rotate_bonus.c \
		bonus/stack_init_bonus.c \
		bonus/stack_utils_bonus.c \
		bonus/stack_utils2_bonus.c \
		bonus/swap_bonus.c

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
	rm -f $(NAME) $(NAME_BONUS)
	rm -f libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
