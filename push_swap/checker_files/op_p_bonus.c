/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:02:18 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:31:00 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_deque *a, t_deque *b, int flag)
{
	if (b->size > 0)
	{
		push_front(a, b->front->data);
		pop_front(b);
	}
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_deque *b, t_deque *a, int flag)
{
	if (a->size > 0)
	{
		push_front(b, a->front->data);
		pop_front(a);
	}
	if (flag == 1)
		write(1, "pb\n", 3);
}
