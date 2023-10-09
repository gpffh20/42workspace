NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = ./

SRCS = *.c

OBJS = ${SRCS:.c=.o}

${NAME}:	${OBJS}
			ar -rc ${NAME} ${OBJS}

all:	${NAME}


.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I${INC}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean
	make all

.PHONY: all clean fclean re
