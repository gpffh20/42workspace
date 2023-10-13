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

typedef struct s_map
{
	double	**map;
	int		row_cnt;
	int		col_cnt;
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
	double	x;
	double	y;
	double	z;
}	t_point;

int		error_handler(char *error_msg);
void	invalid_file(char *file_name);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c, t_map *map_info);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);;
size_t	ft_strlen(const char *s);
void	read_map(char *file_name, t_map *map_info);
void	my_mlx(t_fdf *fdf, char *file_name);
//static t_point init_point(int x, int y, t_map *map_info);
void rotate(double *x, double *y, double *z);
//t_point	*iso(t_point *point);
void draw(t_map *map_info, t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);




//double	**convert_to_double(char **map, t_map *map_info);
//double	**read_map(int fd, int read_len);
//void	right_file(char *title);
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//int		esc_close(int keycode, t_vars *vars);
//void	ft_mlx(t_vars *vars, t_data *img, char *title);
//void	rotate(double *x, double *y, double *z);
//void	DDA(int x1, int y1, int x2, int y2);
//void	set_Pixel(double x, double y);





#endif
