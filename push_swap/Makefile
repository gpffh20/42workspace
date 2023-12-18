NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

INC = ./

COMMON = deque.c\
		op_s.c\
        op_p.c\
        op_r.c\
        op_rr.c\
        ft_atoi.c\
        ft_strdup.c\
        utils.c\
        ft_split.c\
        short_sort.c\
        free.c\
        make_arr.c

SRCS =	$(COMMON)\
		main.c\
		push_swap.c\
		set_stack.c

SRCS_BONUS = $(COMMON)\
			checker.c\
			set_stack_bonus.c\
			ft_strcmp.c\
			./get_next_line/get_next_line.c\
			./get_next_line/get_next_line_utils.c


OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)


$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

$(BONUS):	$(OBJS_BONUS)
			$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@

all:	$(NAME)

bonus:	$(BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
		rm -rf $(NAME) $(BONUS)

re: fclean
	make all

.PHONY: all clean fclean re bonus
