/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:09:01 by eushin            #+#    #+#             */
/*   Updated: 2023/11/05 20:27:43 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_chunk(int size)
{
	int	chunk;

	if (size < 10)
		chunk = 3;
	else if (size < 30)
		chunk = 5;
	else
		chunk = (int)(0.000000053 * size * size + 0.03 * size + 14.5);
	return (chunk);
}

void	a_to_b(t_deque *a, t_deque *b, int i)
{
	int	chunk;

	chunk = get_chunk(a->size);
	while (a->size > 0)
	{
		if (a->front->data <= i)
		{
			pb(b, a);
			i++;
		}
		else if (a->front->data > i && a->front->data <= i + chunk)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else if (a->front->data > (i + chunk))
		{
			if (i < a->size / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
	}
}

void	sort_b(t_deque *b, int len)
{
	int		idx;
	t_node	*tmp;

	idx = 0;
	tmp = b->front;
	while (tmp && tmp->next)
	{
		if (tmp->data == len)
			break ;
		tmp = tmp->next;
		idx++;
	}
	if (idx >= len / 2)
	{
		while (b->front->data != len)
			rrb(b);
	}
	else
	{
		while (b->front->data != len)
			rb(b);
	}
}

void	b_to_a(t_deque *a, t_deque *b)
{
	while (b->size != 0)
	{
		sort_b(b, b->size - 1);
		pa(a, b);
	}
}

void	push_swap(t_deque *a, t_deque *b)
{
	if (a->size <= 5)
		short_sort(a, b);
	else
	{
		a_to_b(a, b, 0);
		b_to_a(a, b);
		return ;
	}
}
