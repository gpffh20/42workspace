/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:14:31 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:30:58 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	set_stack_bonus(a, arr, a->size);
	b = create_deque();
	checker(a, b);
	exit (0);
}
