/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:31:25 by eushin            #+#    #+#             */
/*   Updated: 2023/10/13 07:31:28 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	**convert_to_double(char **map, t_map *map_info)
{
	double	**dmap;
	char	**map_lines;
	int		i;
	int		j;

	dmap = (double **)malloc(sizeof(double *) * (map_info->row_cnt));
	i = 0;
	while (map[i])
	{
		dmap[i] = (double *)malloc(sizeof(double) * map_info->col_cnt);
		map_lines = ft_split(map[i], ' ', map_info);
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

static double	**parse_map(t_map *map_info, int fd)
{
	char	**map;
	char	*buff;
	char	tmp[BUFFER_SIZE + 1];
	int		read_len;

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
		exit(error_handler("Error: read error."));
	map = ft_split(buff, '\n', map_info);
	map_info->width = map_info->col_cnt;
	map_info->height = map_info->row_cnt;
	return (convert_to_double(map, map_info));
}

void	read_map(char *file_name, t_map *map_info)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(error_handler("Error: file open error."));
	map_info->map = parse_map(map_info, fd);
	close(fd);
}
