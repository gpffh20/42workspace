NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra
INC = ./

SRCS =  ft_atoi.c\
		ft_split.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_substr.c\
		main.c\
		error_handle.c\
		read_map.c\
		mlx.c\
		draw.c\
		utils.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx_macos
MLX = $(MLX_DIR)/libmlx.a

$(NAME) :$(OBJS) $(MLX)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c ./fdf.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

all : $(NAME)

clean:
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean: 
	make -C $(MLX_DIR)  clean
	rm -rf $(NAME) $(OBJS)

re: fclean
	make all

.PHONY: all clean fclean re
