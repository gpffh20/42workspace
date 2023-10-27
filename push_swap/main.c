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

int	main(void)
{
	t_deque	*a;

	a = create_deque();
	push_front(a, '1');
	printf("element: %c\n", a->rear->data);
	push_front(a, '2');
	printf("element: %c\n", a->rear->data);
	push_back(a, '3');
	printf("element: %c\n", a->rear->data);

	pop_front(a);
	pop_front(a);
	pop_front(a);
}