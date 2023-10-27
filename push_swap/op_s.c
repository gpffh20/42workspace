/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:53:45 by eushin            #+#    #+#             */
/*   Updated: 2023/10/27 21:53:46 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_deque *a)
{
	t_element	tmp;

	tmp = a->front->data;
	a->front->data = a->front->next->data;
	a->front->next->data = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	t_element	tmp;

	tmp = b->front->data;
	b->front->data = b->front->next->data;
	b->front->next->data = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	sa(a);
	sb(b);
}
