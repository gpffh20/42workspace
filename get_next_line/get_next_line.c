/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:06:48 by eushin            #+#    #+#             */
/*   Updated: 2023/08/05 22:41:30 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_print_list()
{
	return ;
}

t_node*	ft_insert_node(t_node prev, char element)
{
	return ;
}

void	ft_reader(t_node *node, char *tmp)
{
	int	idx;

	idx = 0;
	if (tmp[i] == "/n")
	{
		continue;
	}
	else if (node->data == NULL)
	{
		continue;
	}
	else
	{
		node->data = tmp[i];
		node =
		continue;
	}
	return ;
}

char	*get_next_line(int fd)
{
	static t_node		*buffer; // list
	char				tmp[BUFFER_SIZE + 1];
	int					res;

	res = read(fd, tmp, BUFF_SIZE);
	// 에러이거나 파일이 끝났을 때 null 리턴
	if (res <= 0)
		return NULL;
	buffer = (t_node *)malloc(sizeof(t_node));
	while (!buffer)
	{
		ft_reader(buffer, tmp);
		buffer = buffer->next;
	}








}
