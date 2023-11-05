/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:33:30 by eushin            #+#    #+#             */
/*   Updated: 2023/11/01 23:33:31 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_dup(int *arr, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		if (arr[i] == arr[i + 1])
			exit(print_error(4));
		i++;
	}
}

int	print_error(int code)
{
	write(2, "Error\n", 6);
	printf("error code: %d\n", code);
	return (1);
}