/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:48:23 by eushin            #+#    #+#             */
/*   Updated: 2023/09/10 21:48:36 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_str(char *buff, char **backup)
{
	if (buff != NULL)
		free (buff);
	if (*backup != NULL)
	{
		free (*backup);
		*backup = NULL;
	}
	return (NULL);
}

char	*divide_line(char **backup)
{
	int		idx;
	char	*line;
	char	*tmp;

	tmp = *backup;
	idx = ft_strchr(tmp, '\n');
	line = ft_substr(tmp, 0, idx + 1);
	if (line == NULL)
		return (free_str(NULL, backup));
	*backup = ft_substr(tmp, idx + 1, ft_strlen(tmp));
	free (tmp);
	if (*backup == NULL)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*read_line(int fd, int read_len, char *buff, char **backup)
{
	char	*tmp;
	char	*line;

	while (1)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		buff[read_len] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(*backup, buff);
		free (tmp);
		if (*backup == NULL)
			return (free_str(buff, backup));
		if (ft_strchr(buff, '\n') >= 0)
		{
			free (buff);
			return (divide_line(backup));
		}
	}
	line = NULL;
	if (read_len == 0 && **backup != '\0')
		line = ft_strdup(*backup);
	free_str(buff, backup);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (backup[fd] == NULL)
		backup[fd] = ft_strdup("");
	if (backup[fd] == NULL)
		return (NULL);
	if (ft_strchr(backup[fd], '\n') >= 0)
		return (divide_line(&backup[fd]));
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free_str(NULL, &backup[fd]));
	return (read_line(fd, 0, buff, &backup[fd]));
}
