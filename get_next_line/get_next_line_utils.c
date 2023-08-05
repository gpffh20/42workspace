/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:32 by eushin            #+#    #+#             */
/*   Updated: 2023/08/05 22:41:26 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_insert_node(char element, t_node *node)
{
	t_node	*new;

	new = (t_node *)malloc((sizeof)t_node);
	new->data = element;


}

char	*get_next_line(int fd)
{
	char	tmp[BUFF_SIZE + 1];
	int		res;
	int		idx;
	t_node	*buffer;

	idx = 0;
	res = read(fd, tmp, BUFF_SIZE);
	if (res <= 0)
		return NULL;

	buffer = (t_node *)malloc((sizeof)t_node);
	while (tmp[idx])
	{
		if (tmp[idx] == "\n")
		{

			return buffer
		}
		buffer->data = tmp[idx];
		t_node *new = (t_node *)malloc((sizeof)t_node);
		buffer->next = new;
		buffer = new;
		idx++
	}
}
