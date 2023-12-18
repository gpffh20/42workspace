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

void	do_op(t_deque *a, t_deque *b, char *op)
{
	if (!ft_strncmp(op, "pa", 2))
		pa(a, b, 0);
	else if (!ft_strncmp(op, "pb", 2))
		pb(b, a, 0);
	else if (!ft_strncmp(op, "ra", 2))
		ra(a, 0);
	else if (!ft_strncmp(op, "rb", 2)) // segv
		rb(b, 0);
	else if (!ft_strncmp(op, "rr", 2)) // segv
		rr(a, b, 0);
	else if (!ft_strncmp(op, "rra", 3)) // segv
		rra(a, 0);
	else if (!ft_strncmp(op, "rrb", 3)) // segv
		rrb(b, 0);
	else if (!ft_strncmp(op, "rrr", 3)) // segv
		rrr(a, b, 0);
	else if (!ft_strncmp(op, "sa", 2))
		sa(a, 0);
	else if (!ft_strncmp(op, "sb", 2)) // segv
		sb(b, 0);
	else if (!ft_strncmp(op, "ss", 2)) // segv
		ss(a, b, 0);
	else
		exit(print_error());
}

void	checker(t_deque *a, t_deque *b)
{
	char	*op;

	op = NULL;
	while (1)
	{
		op = get_next_line(0);
		if (!ft_strncmp(op, "(null)", 6))
			break;
		do_op(a, b, op);
	}
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

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
