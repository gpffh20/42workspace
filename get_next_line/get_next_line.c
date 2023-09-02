/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:43:57 by eushin            #+#    #+#             */
/*   Updated: 2023/09/02 22:08:40 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	// 개행 이후 문자열 저장할 버퍼
	static char	*buffer;
	// 출력을 위해 할당할 라인
	char		*line;
	// 작업 위해 일단 복사할 tmp
	char		*tmp;
	int			res;
	int			i;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = read(fd, tmp, BUFFER_SIZE);
	if (res < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			ft_strlcpy(line, tmp, i+1);
			ft_strlcpy(buffer, tmp + i, res - i);
			printf("buffer: %s", buffer);
			free(tmp);
			return line;
		}
//		if (tmp[i] == '\n')
//		{
//			while (tmp[i])
//			{
//				buffer[i] = tmp[i];
//				i++;
//			}
//		}
//		return line;
		i++;
	}




//	// buffer가 비어있나 확인
//	if (ft_strlen(buffer) == 0)
//	{
//		// 비었으면 read
//		// read하고 error check
//		res = read(fd, tmp[BUFFER_SIZE+1], BUFFER_SIZE);
//		if (res < 0)
//			return (NULL);
//		if (res = 0)
//			return line;
//		}
//		else
//			return line;
//	}
//	else
//	{
//		// x -> buffer에 개행이 있나 확인
//		if (ft_strchr())
//			continue;
//		// 안 비어있으면 개행 전까지 line에 할당
//		// 개행 이후는 buffer에 할당
//	}
	return 0;
}
