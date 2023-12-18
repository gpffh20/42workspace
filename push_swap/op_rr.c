/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:21:00 by eushin            #+#    #+#             */
/*   Updated: 2023/11/05 20:25:57 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


void	rra(t_deque *a, int flag)
{
	if (a->size > 0)
	{
		push_front(a, a->back->data);
		pop_back(a);
	}
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_deque *b, int flag)
{
	if (b->size > 0)
	{
		push_front(b, b->back->data);
		pop_back(b);
	}
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b, int flag)
{
	if (a->size > 0 && b->size > 0)
	{
		push_front(a, a->back->data);
		pop_back(a);
		push_front(b, b->back->data);
		pop_back(b);
	}
	if (flag == 1)
		write(1, "rrr\n", 4);
}
