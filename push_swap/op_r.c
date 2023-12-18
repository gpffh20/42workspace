/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:14:47 by eushin            #+#    #+#             */
/*   Updated: 2023/10/27 22:14:48 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_deque *a, int flag)
{
	if (a->size > 0)
	{
		push_back(a, a->front->data);
		pop_front(a);
	}
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_deque *b, int flag)
{
	if (b->size > 0)
	{
		push_back(b, b->front->data);
		pop_front(b);
	}
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b, int flag)
{
	if (a->size > 0 && b->size > 0)
	{
		push_back(a, a->front->data);
		pop_front(a);
		push_back(b, b->front->data);
		pop_front(b);
	}
	if (flag == 1)
		write(1, "rr\n", 3);
}
