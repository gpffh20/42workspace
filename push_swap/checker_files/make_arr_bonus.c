/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:38:49 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:30:59 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	make_arr(t_deque *a, int *arr)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a->front;
	while (i < a->size)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}
