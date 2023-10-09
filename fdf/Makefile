NAME = fdf

CC = gcc

INC = ./libft

SRCS = *.c

OBJS = ${SRCS:.c=.o}

${NAME}:	${OBJS}
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

all:	${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean
	make all

.PHONY: all clean fclean re
