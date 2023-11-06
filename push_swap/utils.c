/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:33:30 by eushin            #+#    #+#             */
/*   Updated: 2023/11/05 20:30:16 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	split_args(int ac, char *av[], t_deque *a)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	while (i < ac)
	{
		j = 0;
		tmp = ft_split(av[i], 32);
		while (tmp[j])
		{
//			printf("str : %s\n", tmp[j]);
			push_back(a, ft_atoi(tmp[j]));
			j++;
		}
		free_str(tmp);
		i++;
	}
}

void	check_dup(int *arr, int limit)
{
	int	i;

	i = 0;
	while (i + 1 < limit)
	{
		if (arr[i] == arr[i + 1])
			exit(print_error());
		i++;
	}
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	is_sorted(t_deque *a)
{
	t_node	*tmp;

	tmp = a->front;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
