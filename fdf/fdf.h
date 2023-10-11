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

typedef struct s_fdf
{
	int	row_cnt;
	int	col_cnt;
}	t_fdf;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int		error_handle(char *str);
double	**convert_to_double(char **map, t_fdf *split_data);
double	**read_map(int fd, int read_len);
void	right_file(char *title);
char	**ft_split(char const *s, char c, t_fdf *split_data);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		esc_close(int keycode, t_vars *vars);

#endif
