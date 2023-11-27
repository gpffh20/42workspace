NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

INC = ./

SRCS =	pipex.c\
		ft_split.c\
		ft_strnstr.c\
		ft_strjoin.c\
		ft_strdup.c\
		error_handle.c\
		execute.c\
		init_arg.c\
		get_path.c\
		get_cmd_path.c\
		ft_putstr_fd.c\


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
