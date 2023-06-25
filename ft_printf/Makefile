NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = ./

SRCS = char_str.c ft_printf.c ft_strlen.c int_hex_ptr.c

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

re: fclean all

.PHONY: all clean fclean re
