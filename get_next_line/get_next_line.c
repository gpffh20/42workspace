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

	idx = ft_strchr(str, '\n');
//	printf("idx: %d, str: %s\n", idx, str);
	if (idx < 0)
	{
		*buffer = ft_strjoin(*buffer, str);
		return (*buffer);
	}
	line = ft_substr(str, 0, idx + 1);
	if (ft_strchr(*buffer, '\n') < 0)
	{
		line = ft_strjoin(*buffer, line);
	}
	*buffer = ft_substr(str, idx + 1, ft_strlen(str));
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
	if (!tmp || !line)
		return (NULL);

	if (ft_strchr(buffer, '\n') >= 0)
		return (check_new_line(buffer, &buffer));

	while (1)
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		if (read_len < 0)
			return (NULL);
//		EoF 처리
		if (read_len == 0)
			return (NULL);
		line = check_new_line(tmp, &buffer);
		if (ft_strchr(tmp, '\n') >= 0)
			break;
	}
	return (line);
}
