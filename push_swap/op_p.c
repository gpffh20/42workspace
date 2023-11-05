/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:02:18 by eushin            #+#    #+#             */
/*   Updated: 2023/11/05 20:25:14 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	if (b->size > 0)
	{
		push_front(a, b->front->data);
		pop_front(b);
	}
	write(1, "pa\n", 3);
}

void	pb(t_deque *b, t_deque *a)
{
	if (a->size > 0)
	{
		push_front(b, a->front->data);
		pop_front(a);
	}
	write(1, "pb\n", 3);
}
