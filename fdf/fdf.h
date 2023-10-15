/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:37:28 by eyshin            #+#    #+#             */
/*   Updated: 2023/10/10 15:37:37 by eyshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map
{
	int		**map;
	int		row_cnt;
	int		width;
	int		height;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c, t_map *map_info);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);;
size_t	ft_strlen(const char *s);
void	free_str(char **ret, int i);
void	free_int(int **ret, int i);
int		ft_min(int a, int b);
int		error_handler(char *error_msg);
void	invalid_file(char *file_name);
void	read_map(char *file_name, t_map *map_info);
void	my_mlx(t_fdf *fdf, char *file_name);
void	draw(t_map *map_info, t_fdf *fdf);
int		esc_close(int keycode, t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);


#endif
