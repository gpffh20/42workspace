#include "fdf.h"

int	error_handle(char *str)
{
	perror(str);
	return (1);
}

double	**convert_to_double(char **map, t_fdf *split_info)
{
	double	**dmap;
	char	**map_lines;
	int		i;
	int		j;

	dmap = (double **)malloc(sizeof(double *) * (split_info->row_cnt));
	i = 0;
	while (map[i])
	{
		dmap[i] = (double *)malloc(sizeof(double) * split_info->col_cnt);
		map_lines = ft_split(map[i], ' ', split_info);
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
	t_fdf	split_info;

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
	map = ft_split(buff, '\n', &split_info);
	return (convert_to_double(map, &split_info));
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

	if (ac != 2)
		exit(error_handle("Error: 인자 수 에러"));
	right_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(error_handle("Error: open 에러"));
	dmap = read_map(fd, 0);
	printf("%f", dmap[0][0]);
	return (0);
}
