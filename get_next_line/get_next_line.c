/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:43:57 by eushin            #+#    #+#             */
/*   Updated: 2023/09/02 22:33:57 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*divide_line(char *str, char **buffer)
{
	int		idx;
	char	*line;

	idx = ft_strchr(str, '\n');
//	printf("idx: %d, str: %s\n", idx, str);
	if (idx < 0)
	{
		*buffer = NULL;
		return (str);
	}
	line = ft_substr(str, 0, idx + 1);
	*buffer = ft_substr(str, idx + 1, ft_strlen(str));
	printf("test buffer: %s, line: %s\n", *buffer, line);
	printf("=================================\n");
	return line;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	int			read_len;


	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);

	if (ft_strchr(buffer, '\n') >= 0)
		return (divide_line(buffer, &buffer));

	while (1)
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		printf("1// buffer: %s, tmp: %s\n", buffer, tmp);
		if (read_len <= 0)
			return (NULL);
		tmp[read_len] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(tmp, '\n') >= 0)
			return (divide_line(buffer, &buffer));
		printf("buffer: %s, tmp: %s\n", buffer, tmp);
	}
}
