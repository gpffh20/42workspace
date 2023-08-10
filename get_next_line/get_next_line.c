/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:43:57 by eushin            #+#    #+#             */
/*   Updated: 2023/08/08 05:03:34 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		tmp[BUFFER_SIZE + 1];
	int			res;
	int			i;

	res = read(fd, tmp, BUFFER_SIZE);
	if (res <= 0)
		return NULL;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

	i = 0;
	while (1)
	{
		if (!tmp[i])
		{
			res = read(fd, tmp, BUFFER_SIZE);
			if (res <= 0)
				return NULL;
			i = -1;
		}
		else if (tmp[i] == '\n')
		{
			line[i] = '\n';
			break;
		}
		else
			line[i] = tmp[i];
		i++;	
	}
	return line;
}
