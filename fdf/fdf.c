#include "fdf.h"

void	read_map(int fd)
{
	char	*buff;
	char	*tmp;
	int		read_len;
	char	**map;
	char	**map_lines;
	double	**dmap;
	int		i;
	int		j;

	buff = ft_strdup("");
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		tmp[read_len] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	if (!buff)
	{
		perror("Error: read error.");
		exit(1);
	}
	free(tmp);
	map = ft_split(buff, '\n');
	dmap = (double **)malloc(sizeof(double *) * ())
	i = 0;
	while (map[i])
	{
		map_lines = split(map[i], ' ');
		j = 0;
		while (map_lines[j])
		{


		}
		free(map[i]);
		i++;
	}
	return ;
}

void	right_file(char *title)
{
	int	max_idx;

	max_idx = ft_strlen(title);
	if (ft_strncmp(ft_substr(title, max_idx-4, 4), ".fdf", 4))
		return ;
	perror("Error: 입력 파일 확장자");
	exit(1);
}

int main(int ac, char *av[])
{
	int	fd;

	if (ac != 2)
	{
		perror("Error.");
		exit(1);
	}

	right_file(av[1]);

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error.");
		exit(1);
	}

	read_map(fd);
	return (0);
}
