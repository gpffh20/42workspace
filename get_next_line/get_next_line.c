/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:43:57 by eushin            #+#    #+#             */
/*   Updated: 2023/09/10 20:10:54 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



char	*divide_line(char **buffer)
{
	int		idx;
	char	*line;
	char	*tmp;

	tmp = *buffer;
	idx = ft_strchr(tmp, '\n');
	line = ft_substr(tmp, 0, idx + 1);
	*buffer = ft_substr(tmp, idx + 1, ft_strlen(tmp));
	free (tmp);
	return line;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*tmp_buff;
	int			read_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = ft_strdup("");
		if (buffer == NULL)
			return (NULL);
	}
	if (ft_strchr(buffer, '\n') >= 0)
		return (divide_line(&buffer));
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free (buffer);
		return (NULL);
	}

	while (1)
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(tmp);
			free(buffer);
			buffer = 0;
			return (NULL);
		}
		else if (read_len == 0)
		{
			char *line = NULL;
			if (*buffer != '\0')
				line = ft_strdup(buffer);
			free (buffer);
			free (tmp);
			buffer = NULL;
			return (line);
		}
		tmp[read_len] = '\0';
		tmp_buff = buffer;
		buffer = ft_strjoin(buffer, tmp);
		free (tmp_buff);
		if (ft_strchr(tmp, '\n') >= 0)
		{
			free(tmp);
			return (divide_line(&buffer));
		}
	}
}
