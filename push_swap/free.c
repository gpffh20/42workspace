/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:33:30 by eushin            #+#    #+#             */
/*   Updated: 2023/11/12 17:31:25 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_deque(t_deque *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->front;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
