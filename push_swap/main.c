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

void print_arr(int *arr, int ac) {
	int i = 0;
	while (i < ac) {
		printf("arr: %d\n", arr[i]);
		i++;
	}
}

void print_deque(t_deque *deque) {
	t_node *node;

	for (node = deque->front; node != NULL; node = node->next)
		printf("[%d] ", node->data);
	printf("\n");
}


int	main(int ac, char *av[])
{
	t_deque	*a;
	t_deque	*b;
	int		i;
	int		*arr;

	if (ac < 2)
		return (print_error(1));
	a = create_deque();
	b = create_deque();
	arr = (int *) malloc(sizeof(int) * ac);
	i = 1;
	while (i < ac)
	{

		arr[i - 1] = ft_atoi(av[i]);
		check_dup(arr, arr[i - 1], i - 1);
		i++;
	}
	set_stack(a, arr, ac - 1);
	push_swap(a, b, ac - 1);
	printf("a: ");
	print_deque(a);
	printf("b: ");
	print_deque(b);

}