/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:09:01 by eushin            #+#    #+#             */
/*   Updated: 2023/11/02 00:09:02 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	triplicate(t_deque *a, t_deque *b, int len)
{
	t_element	pivot1;
	t_element	pivot2;
	int			i;

	pivot1 = len / 3 - 1;
	pivot2 = 2 * len / 3 - 1;
	i = 0;
	while (i < len)
	{
		if (a->front->data <= pivot1)
		{
			pb(b, a);
			rb(b);
		}
		else if (a->front->data <= pivot2)
		{
			pb(b, a);
		}
		else
		{
			ra(a);
		}
		i++;
	}
	while (a->size > 3)
		pb(b, a);
	under_three(a);
}

void	case_three(t_deque *a)
{
	if (a->front->data == 1 && a->back->data == 2)
		sa(a);
	else if (a->front->data == 2 && a->back->data == 0)
	{
		sa(a);
		rra(a);
	}
	else if (a->front->data == 2 && a->back->data == 1)
		ra(a);
	else if (a->front->data == 0 && a->back->data == 1)
	{
		sa(a);
		ra(a);
	}
	else if (a->front->data == 1 && a->back->data == 0)
		rra(a);
}

void	under_three(t_deque *a)
{
	if (a->size == 1)
		exit(1);
	else if (a->size == 2)
	{
		if (a->front->data > a->back->data)
			sa(a);
	}
	else
		case_three(a);
}

//void	greedy(t_deque *a, t_deque *b)
//{
//	int	a_data;
//	int b_data;
//
//	while (b->size)
//	{
//		find_best(a, b, &a_data, &b_data);
//		before_push_all(a, b, &a_data, &b_data);
//		before_push_single(a, b, &a_data, &b_data);
//		push(a, b);
//	}
//	last_sort(a);
//}

void	find_best(t_deque *a, t_deque *b)
{
	return ;
}

void	push_swap(t_deque *a, t_deque *b, int len)
{
	if (a->size <= 3)
		under_three(a);
	else
	{
		triplicate(a, b, len);
	}
	while (b->size)
	{
		find_best(a, b);
	}


}

