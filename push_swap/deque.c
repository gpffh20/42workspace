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
	deque->rear = NULL;
	deque->front = NULL;
	return (deque);
}

void	push_front(t_deque *deque, t_element data)
{
	t_deque_node	*new;

	new = (t_deque_node *)malloc(sizeof(t_deque_node));
	new->data = data;
	if (deque->size == 0)
	{
		new->next = NULL;
		new->pre = NULL;
		deque->rear = new;
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
	t_deque_node	*new;

	new = (t_deque_node *)malloc(sizeof(t_deque_node));
	new->data = data;
	if (deque->size == 0)
	{
		new->next = NULL;
		new->pre = NULL;
		deque->rear = new;
		deque->front = new;
	}
	else
	{
		new->next = NULL;
		new->pre = deque->rear;
		deque->rear->next = new;
		deque->rear = new;
	}
	deque->size++;
}

void	pop_front(t_deque *deque)
{
	t_deque_node	*tmp;

	if (deque->size == 1)
	{
		deque->front = NULL;
		deque->rear = NULL;
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
	t_deque_node	*tmp;

	if (deque->size == 1)
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		tmp = deque->rear;
		deque->rear = tmp->pre;
		deque->rear->next = NULL;
		free(tmp);
	}
	deque->size--;
}