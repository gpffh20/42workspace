/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:25:09 by eushin            #+#    #+#             */
/*   Updated: 2023/12/17 19:25:11 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	checker(t_deque *a, t_deque *b)
{
	char	*op;

	op = NULL;
	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break;
		do_op(a, b, op);
		free(op);
	}
	if (b->size == 0 && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

