/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:09:44 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:30:36 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
