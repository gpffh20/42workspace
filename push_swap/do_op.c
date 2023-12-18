/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:12:36 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 13:14:19 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_op(t_deque *a, t_deque *b, char *op)
{
	if (!ft_strcmp(op, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(op, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(op, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(op, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(op, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(op, "ss\n"))
		ss(a, b, 0);
	else
		exit(print_error());
}

