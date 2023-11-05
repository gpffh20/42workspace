/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:42:41 by eushin            #+#    #+#             */
/*   Updated: 2023/11/05 20:24:29 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_deque	*a;
	t_deque	*b;
	int		idx;
	int		*arr;

	if (ac < 2)
		return (print_error());
	a = create_deque();
	// arr = (int *) malloc(sizeof(int) * ac);
	idx = split_args(ac, av, arr);
	set_stack(a, arr, idx);
	// free(arr);
	b = create_deque();
	push_swap(a, b);
	exit (0);
}
