/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:56:54 by eushin            #+#    #+#             */
/*   Updated: 2023/11/05 20:29:49 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	case_three(t_deque *a)
{
	if (a->front->data > a->back->data)
	{
		if (a->front->data < a->front->next->data)
			rra(a);
		else if (a->back->pre->data > a->back->data)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else
	{
		if (a->front->data > a->front->next->data)
			sa(a);
		else
		{
			sa(a);
			ra(a);
		}
	}
}

void	case_four(t_deque *a, t_deque *b)
{
	int		idx;
	t_node	*tmp;

	idx = 0;
	tmp = a->front;
	while (1)
	{
		if (tmp->data == 0)
			break ;
		tmp = tmp->next;
		idx++;
	}
	if (idx < 2)
		while (a->front->data != 0)
			ra(a);
	else
		while (a->front->data != 0)
			rra(a);
	if (!is_sorted(a))
	{
		pb(b, a);
		case_three(a);
		pa(a, b);
	}
}

void	case_five(t_deque *a, t_deque *b)
{
	while (a->size > 3)
	{
		if (a->front->data == 0 || a->front->data == 1)
			pb(b, a);
		else
			ra(a);
	}
	if (is_sorted(b))
		sb(b);
	if (!is_sorted(a))
		case_three(a);
	pa(a, b);
	pa(a, b);
}

void	short_sort(t_deque *a, t_deque *b)
{
	if (a->size == 1)
		exit(1);
	else if (a->size == 2)
	{
		if (a->front->data > a->back->data)
			sa(a);
	}
	else if (a->size == 3)
		case_three(a);
	else if (a->size == 4)
		case_four(a, b);
	else
		case_five(a, b);
}
