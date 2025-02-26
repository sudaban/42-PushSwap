NAME = push_swap
LIBFT = libft
LIBFTM = $(LIBFT)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c a_rules.c b_rules.c sort.c sorts.c utils.c helper.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTM) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
