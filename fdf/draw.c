/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:23:11 by eushin            #+#    #+#             */
/*   Updated: 2023/10/16 00:52:34 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	bresenham(t_point f, t_point s, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(s.x - f.x);
	delta.y = abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		my_mlx_pixel_put(fdf, cur.x, cur.y, 0xF00FFFFF);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static void	iso(t_point *point)
{
	int		prev_x;
	int		prev_y;
	double	theta;

	prev_x = point->x;
	prev_y = point->y;
	theta = M_PI / 6;
	point->x = prev_x * cos(theta) - prev_y * cos(theta);
	point->y = prev_x * sin(theta) + prev_y * sin(theta) - point->z;
	return ;
}

static t_point	init_point(int x, int y, t_map *map_info)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map_info->map[y][x];
	return (point);
}

static t_point	relocate(t_point point, t_map *map)
{
	int	zoom;

	zoom = ft_min(WIDTH / map->width / 3, HEIGHT / map->height / 3);
	point.x *= zoom;
	point.y *= zoom;
	point.z *= zoom;
	point.x -= (map->width * zoom) / 2;
	point.y -= (map->height * zoom) / 2;
	iso(&point);
	point.x += WIDTH / 2;
	point.y += HEIGHT / 2;
	return (point);
}

void	draw(t_map *map_info, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (x != map_info->width - 1)
				bresenham(relocate(init_point(x, y, map_info), map_info),
					relocate(init_point(x + 1, y, map_info), map_info), fdf);
			if (y != map_info->height - 1)
				bresenham(relocate(init_point(x, y, map_info), map_info),
					relocate(init_point(x, y + 1, map_info), map_info), fdf);
			x++;
		}
		y++;
	}
	free_int(map_info->map, map_info->height);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return ;
}
