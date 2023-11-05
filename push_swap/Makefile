NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
# -fsanitize=address -g3

INC = ./

SRCS =	main.c\
		deque.c\
		op_s.c\
		op_p.c\
		op_r.c\
		op_rr.c\
		ft_atoi.c\
		ft_strdup.c\
		utils.c\
		set_stack.c\
		push_swap.c\
		ft_split.c\
		short_sort.c\
		free.c\



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
