NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LIB = -Llibft -lft

INCLUDES = -Iincludes

MAIN = pipex.c 

SRC = inits_and_frees.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): ${OBJ}
	make re -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ ${MAIN} ${OBJ} $(LIB)

clean:
	@$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean