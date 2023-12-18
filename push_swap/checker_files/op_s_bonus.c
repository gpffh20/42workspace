/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:53:45 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:31:03 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_deque *a, int flag)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->front->data;
		a->front->data = a->front->next->data;
		a->front->next->data = tmp;
	}
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_deque *b, int flag)
{
	int	tmp;

	if (b->size > 1)
	{
		tmp = b->front->data;
		b->front->data = b->front->next->data;
		b->front->next->data = tmp;
	}
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b, int flag)
{
	int	tmp;

	if (a->size > 1 && b->size > 1)
	{
		tmp = a->front->data;
		a->front->data = a->front->next->data;
		a->front->next->data = tmp;
		tmp = b->front->data;
		b->front->data = b->front->next->data;
		b->front->next->data = tmp;
	}
	if (flag == 1)
		write(1, "ss\n", 3);
}
