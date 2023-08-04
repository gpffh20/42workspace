/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:06:48 by eushin            #+#    #+#             */
/*   Updated: 2023/08/04 22:42:51 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_insert_node(t_node prev, char element)
{
	return ;
}

void	ft_reader(t_node node)
{
	return ;
}

char	*get_next_line(int fd)
{
	t_node	buffer; // list
	char		tmp[BUFF_SIZE + 1];
	int			res;

	res = read(fd, tmp, BUFF_SIZE);
	// 에러이거나 파일이 끝났을 때 null 리턴
	if (res <= 0)
		return NULL;
	
	while (1)
	{
		ft_reader
		
	}








}
