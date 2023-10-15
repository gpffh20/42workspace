/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:31:25 by eushin            #+#    #+#             */
/*   Updated: 2023/10/16 00:53:00 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	**convert_to_int(char **map, t_map *map_info)
{
	int		**imap;
	char	**map_lines;
	int		i;
	int		j;

	imap = (int **) malloc(sizeof(int *) * (map_info->height));
	i = 0;
	while (i < map_info->height)
	{
		map_lines = ft_split(map[i], ' ', map_info);
		imap[i] = (int *) malloc(sizeof(int) * map_info->row_cnt);
		j = 0;
		while (j < map_info->row_cnt)
		{
			imap[i][j] = ft_atoi(map_lines[j]);
			j++;
		}
		free_str(map_lines, j);
		i++;
	}
	map_info->width = map_info->row_cnt;
	free(map);
	return (imap);
}

static int	**parse_map(t_map *map_info, int fd)
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
	map_info->height = map_info->row_cnt;
	return (convert_to_int(map, map_info));
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
