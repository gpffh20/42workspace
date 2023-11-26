NAME = pipex

CC = cc
#CFLAGS = -Wall -Werror -Wextra

INC = ./

SRCS =	pipex.c\


OBJS = $(SRCS:.c=.o)

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

$(NAME):	$(OBJS) $(PRINTF)
			$(CC) $(CFLAGS) -L$(PRINTF_DIR) $^ -o $@

$(PRINTF):
			make -C $(PRINTF_DIR)

all:	$(NAME)

%.o: %.c ./pipex.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)
#.c.o:
#	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	make -C $(PRINTF_DIR) clean
	rm -rf $(OBJS)

fclean:
	make -C $(PRINTF_DIR)  clean
	rm -rf $(NAME) $(OBJS)

re: fclean
	make all

.PHONY: all clean fclean re
