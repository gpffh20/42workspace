#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_fdf
{
	char **map;
	int row_cnt;
	int col_cnt;
}	t_fdf;


char	**ft_split(char const *s, char c, t_fdf *split_info);

#endif
