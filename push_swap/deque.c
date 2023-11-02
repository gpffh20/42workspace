/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:40:37 by eushin            #+#    #+#             */
/*   Updated: 2023/10/27 14:40:41 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_deque	*create_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	deque->size = 0;
	deque->back = NULL;
	deque->front = NULL;
	return (deque);
}

void	push_front(t_deque *deque, t_element data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	if (deque->size == 0)
	{
		new->next = NULL;
		new->pre = NULL;
		deque->back = new;
		deque->front = new;
	}
	else
	{
		new->pre = NULL;
		new->next = deque->front;
		deque->front->pre = new;
		deque->front = new;
	}
	deque->size++;
}

void	push_back(t_deque *deque, t_element data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	if (deque->size == 0)
	{
		new->next = NULL;
		new->pre = NULL;
		deque->back = new;
		deque->front = new;
	}
	else
	{
		new->next = NULL;
		new->pre = deque->back;
		deque->back->next = new;
		deque->back = new;
	}
	deque->size++;
}

void	pop_front(t_deque *deque)
{
	t_node	*tmp;

	if (deque->size == 1)
	{
		deque->front = NULL;
		deque->back = NULL;
	}
	else
	{
		tmp = deque->front;
		deque->front = tmp->next;
		deque->front->pre = NULL;
		free(tmp);
	}
	deque->size--;
}

void	pop_back(t_deque *deque)
{
	t_node	*tmp;

	if (deque->size == 1)
	{
		deque->front = NULL;
		deque->back = NULL;
	}
	else
	{
		tmp = deque->back;
		deque->back = tmp->pre;
		deque->back->next = NULL;
		free(tmp);
	}
	deque->size--;
}