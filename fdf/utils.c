/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:53:13 by eushin            #+#    #+#             */
/*   Updated: 2023/10/16 00:53:19 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	max_flag(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	free_int(int **ret, int i)
{
	while (i)
		free(ret[--i]);
	free(ret);
	return ;
}

void	free_str(char **ret, int i)
{
	while (i)
		free(ret[--i]);
	free(ret);
	return ;
}

int	ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}
