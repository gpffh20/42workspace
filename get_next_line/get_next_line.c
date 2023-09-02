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
	// 개행 이후 문자열 저장할 버퍼
	static char	*buffer;
	// 출력을 위해 할당할 라인
	char		*line;
	// 작업 위해 일단 복사할 tmp
	char		tmp[BUFFER_SIZE+1];
	int			res;
	int			i;

	// buffer가 비어있나 확인
	// x -> buffer에 개행이 있나 확인
	// o -> EoF 확인

	// 비었으면 read
	// read하고 error check

	// 안 비어있으면 개행 전까지 line에 할당
	// 개행 이후는 buffer에 할당


	res = read(fd, tmp, BUFFER_SIZE);
	if (res <= 0)
		return NULL;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE+1));
	memcpy(line, tmp, BUFFER_SIZE+1);

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

