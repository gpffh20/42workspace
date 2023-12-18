/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:42:41 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 13:24:08 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_deque	*a;
	t_deque	*b;
	int		*arr;

	if (ac < 2)
		return (0);
	a = create_deque();
	split_args(ac, av, a);
	arr = (int *) malloc(sizeof(int) * a->size);
	make_arr(a, arr);
	set_stack(a, arr, a->size);
	b = create_deque();
	push_swap(a, b);
	exit (0);
}
