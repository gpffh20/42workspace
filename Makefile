NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = ./

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

AR = ar -rc

all: ${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I${INC}


clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
