NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = ./

SRCS = ft_printf.c ft_strlen.c print_char.c print_int.c print_hex_ptr.c print_str.c

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
