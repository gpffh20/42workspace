/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:33:59 by eushin            #+#    #+#             */
/*   Updated: 2023/10/10 13:02:20 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error_handle(char *str)
{
	perror(str);
	return (1);
}

double	**convert_to_double(char **map, t_fdf *split_data)
{
	double	**dmap;
	char	**map_lines;
	int		i;
	int		j;

	dmap = (double **)malloc(sizeof(double *) * (split_data->row_cnt));
	i = 0;
	while (map[i])
	{
		dmap[i] = (double *)malloc(sizeof(double) * split_data->col_cnt);
		map_lines = ft_split(map[i], ' ', split_data);
		j = 0;
		while (map_lines[j])
		{
			dmap[i][j] = (double)ft_atoi(map_lines[j]);
			j++;
		}
		i++;
	}
	free(map);
	return (dmap);
}

double	**read_map(int fd, int read_len)
{
	char	*buff;
	char	tmp[BUFFER_SIZE + 1];
	char	**map;
	t_fdf	split_data;

	buff = ft_strjoin("", "");
	while (1)
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		tmp[read_len] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	if (!buff)
		exit(error_handle("Error: read error."));
	map = ft_split(buff, '\n', &split_data);
	return (convert_to_double(map, &split_data));
}

void	right_file(char *title)
{
	int	max_idx;

	max_idx = ft_strlen(title);
	if (ft_strncmp(ft_substr(title, max_idx - 4, 4), ".fdf", 4))
		return ;
	exit(error_handle("Error: 입력 파일 확장자 에러"));
}

int	main(int ac, char *av[])
{
	int		fd;
	double	**dmap;
	t_data	img;
	t_vars	vars;

	if (ac != 2)
		exit(error_handle("Error: 인자 수 에러"));
	right_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(error_handle("Error: open 에러"));
	dmap = read_map(fd, 0);
	close(fd);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1500, 850, av[1]);
	img.img = mlx_new_image(vars.mlx, 1500, 850);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, esc_close, &vars);
	mlx_loop(vars.mlx);
	printf("%f", dmap[0][0]);
	return (0);
}
