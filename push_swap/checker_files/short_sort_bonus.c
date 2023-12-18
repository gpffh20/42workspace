/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:56:54 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:31:07 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	case_three(t_deque *a)
{
	if (a->front->data > a->back->data)
	{
		if (a->front->data < a->front->next->data)
			rra(a, 1);
		else if (a->back->pre->data > a->back->data)
		{
			sa(a, 1);
			rra(a, 1);
		}
		else
			ra(a, 1);
	}
	else
	{
		if (a->front->data > a->front->next->data)
			sa(a, 1);
		else
		{
			sa(a, 1);
			ra(a, 1);
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
			ra(a, 1);
	else
		while (a->front->data != 0)
			rra(a, 1);
	if (!is_sorted(a))
	{
		pb(b, a, 1);
		case_three(a);
		pa(a, b, 1);
	}
}

void	case_five(t_deque *a, t_deque *b)
{
	while (a->size > 3)
	{
		if (a->front->data == 0 || a->front->data == 1)
			pb(b, a, 1);
		else
			ra(a, 1);
	}
	if (is_sorted(b))
		sb(b, 1);
	if (!is_sorted(a))
		case_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	short_sort(t_deque *a, t_deque *b)
{
	if (a->size == 1)
		exit(1);
	else if (a->size == 2)
	{
		if (a->front->data > a->back->data)
			sa(a, 1);
	}
	else if (a->size == 3)
		case_three(a);
	else if (a->size == 4)
		case_four(a, b);
	else
		case_five(a, b);
}
