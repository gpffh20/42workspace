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
	t_deque *b;

	a = create_deque();
	b = create_deque();
	push_back(a, '1');
	push_back(a, '2');
	push_back(a, '3');

	push_back(b, '4');
	push_back(b, '5');
	push_back(b, '6');

	print_deque(a); print_deque(b);

	rra(a);
	rrb(b);
	rrr(a, b);

	printf("a: "); print_deque(a);
	printf("b: "); print_deque(b);

}