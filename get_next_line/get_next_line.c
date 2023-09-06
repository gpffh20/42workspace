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

char	*check_new_line(char *str, char **buffer)
{
	int		idx;
	char	*line;
	char	*tmp;

	idx = ft_strchr(str, '\n');
	printf("idx: %d, str: %s\n", idx, str);
	if (idx < 0)
	{
		*buffer = NULL;
		return (str);
	}
	line = ft_substr(str, 0, idx + 1);
	line = ft_strjoin(*buffer, line);
	*buffer = ft_substr(str, idx + 1, ft_strlen(str) - idx - 1);
	printf("buffer: %s, line: %s\n", *buffer, line);
	return line;
}

char	*get_next_line(int fd)
{

	static char	*buffer;
	char		*line;
	char		*tmp;
	int			read_len;


	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));


	printf("len: %zu\n", ft_strlen(buffer));
	if (ft_strchr(buffer, '\n') > 0)
		return (check_new_line(buffer, &buffer));

	while (1)
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		printf("tmp: %s\n", tmp);
		if (read_len < 0)
			return (NULL);
//		EoF 처리
		if (read_len == 0)
			return (line);
		line = check_new_line(tmp, &buffer);
		break;
	}
	return (line);
}
