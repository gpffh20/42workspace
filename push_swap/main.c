/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:42:41 by eushin            #+#    #+#             */
/*   Updated: 2023/10/27 14:42:43 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void print_deque(t_deque *deque)
{
	t_deque_node *node;

	for(node = deque->front; node != NULL; node = node->next)
		printf("[%c] ", node->data);
	printf("\n");
}

int	main(void)
{
	t_deque *a;

	a = create_deque();
	push_front(a, '1');
	push_front(a, '2');
	push_back(a, '3');
	print_deque(a);

	sa(a);

	print_deque(a);
}