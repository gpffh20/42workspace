NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

INC = ./

SRCS =	main.c deque.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
