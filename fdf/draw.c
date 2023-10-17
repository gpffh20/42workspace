/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:23:11 by eushin            #+#    #+#             */
/*   Updated: 2023/10/16 16:53:40 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	bresenham(t_point s, t_point f, t_fdf *fdf)
{
	t_point	delta;
	t_point	cur;
	int		d[2];

	delta.x = abs(f.x - s.x);
	delta.y = abs(f.y - s.y);
	d[0] = delta.x - delta.y;
	cur = s;
	while (cur.x != f.x || cur.y != f.y)
	{
		my_mlx_pixel_put(fdf, cur.x, cur.y, 0xF89B00);
		d[1] = d[0] * 2;
		if (-d[1] < delta.y)
		{
			d[0] -= delta.y;
			cur.x += max_flag(s.x, f.x);
		}
		if (d[1] < delta.x)
		{
			d[0] += delta.x;
			cur.y += max_flag(s.y, f.y);
		}
	}
}

static void	rotate_x(t_point *point)
{
	t_point	cur;

	cur.y = point->y;
	cur.z = point->z;
	point->y = cur.y * cos(asin(tan(M_PI / 6)))
		- cur.z * sin(asin(tan(M_PI / 6)));
	point->z = cur.y * sin(asin(tan(M_PI / 6)))
		+ cur.z * cos(asin(tan(M_PI / 6)));
}

static void	rotate_z(t_point *point)
{
	t_point	cur;

	cur.x = point->x;
	cur.y = point->y;
	point->x = cur.x * cos(M_PI / 4) - cur.y * sin(M_PI / 4);
	point->y = cur.x * sin(M_PI / 4) + cur.y * cos(M_PI / 4);
}

static t_point	relocate(t_point point, t_map *map)
{
	int	zoom;

	if (map->width * map->height < 200000)
		zoom = ft_min(WIDTH / map->width / 3, HEIGHT / map->height / 3);
	else
		zoom = 1;
	point.x *= zoom;
	point.y *= zoom;
	point.z *= zoom;
	rotate_z(&point);
	rotate_x(&point);
	point.x += WIDTH / 2;
	point.y += HEIGHT / 2;
	point.y -= HEIGHT / 4;
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
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return ;
}
