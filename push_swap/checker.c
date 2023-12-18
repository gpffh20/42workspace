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
	if (!ft_strcmp(op, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(op, "pb"))
		pb(b, a, 0);
	else if (!ft_strcmp(op, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(op, "rb"))
		rb(b, 0);
	else if (!ft_strcmp(op, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(op, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(op, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(op, "rrr"))
		rrr(a, b, 0);
	else if (!ft_strcmp(op, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(op, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(op, "ss"))
		ss(a, b, 0);
	else
		exit(print_error());
}

#include <stdio.h>
void print_deque(t_deque *a)
{
	t_node *node;

	node = a->front;
	while (node)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}

void	checker(t_deque *a, t_deque *b)
{
	char	*op;

	op = NULL;
	print_deque(a);
	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break;
		do_op(a, b, op);
	}
	print_deque(a);
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