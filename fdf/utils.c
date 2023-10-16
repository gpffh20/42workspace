/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:53:13 by eushin            #+#    #+#             */
/*   Updated: 2023/10/16 18:01:07 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	max_flag(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	free_int(int **ret, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

void	free_str(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

int	ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

t_point	init_point(int x, int y, t_map *map_info)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map_info->map[y][x];
	return (point);
}
