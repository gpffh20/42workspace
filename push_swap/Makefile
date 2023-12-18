NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

INC = ./

SRCS_DIR = ./push_swap_files/

BONUS_DIR = ./checker_files/

SRCS = \
		deque.c\
		op_s.c\
        op_p.c\
        op_r.c\
        op_rr.c\
        ft_atoi.c\
        ft_strdup.c\
        ft_split.c\
        short_sort.c\
        free.c\
        make_arr.c\
        split_args.c\
        check_dup.c\
        print_error.c\
        is_sorted.c\
		main.c\
		push_swap.c\
		set_stack.c

SRCS_BONUS = \
		deque_bonus.c\
		op_s_bonus.c\
        op_p_bonus.c\
        op_r_bonus.c\
        op_rr_bonus.c\
        ft_atoi_bonus.c\
        ft_strdup_bonus.c\
        ft_split_bonus.c\
        short_sort_bonus.c\
        free_bonus.c\
        make_arr_bonus.c\
        split_args_bonus.c\
        check_dup_bonus.c\
        print_error_bonus.c\
        is_sorted_bonus.c\
		main_bonus.c\
		checker_bonus.c\
		set_stack_bonus.c\
		ft_strcmp_bonus.c\
		do_op_bonus.c\
		../get_next_line/get_next_line.c\
		../get_next_line/get_next_line_utils.c


OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

OBJS_BONUS = $(addprefix $(BONUS_DIR), $(SRCS_BONUS:.c=.o))


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
