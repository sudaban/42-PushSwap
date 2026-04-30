NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = Mandatory/main.c \
      Mandatory/GC/GC.c \
      Mandatory/OP/Operations.c \
      Mandatory/Utils/Utils.c \
      Mandatory/Utils/String.c \
      Mandatory/Utils/Parse.c \
      Mandatory/Utils/Print.c \
      Mandatory/Core/Core.c

OBJ_DIR = obj
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re