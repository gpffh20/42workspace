/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:21:00 by eushin            #+#    #+#             */
/*   Updated: 2023/10/27 22:21:02 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_deque *a)
{
	push_front(a, a->back->data);
	pop_back(a);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b)
{
	push_front(b, b->back->data);
	pop_back(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	push_front(a, a->back->data);
	pop_back(a);
	push_front(b, b->back->data);
	pop_back(b);
	write(1, "rrr\n", 4);
}