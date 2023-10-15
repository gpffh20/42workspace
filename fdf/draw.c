/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:23:11 by eushin            #+#    #+#             */
/*   Updated: 2023/10/11 11:23:12 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

//void draw(t_map *map_info, t_fdf *fdf)
//{
//	for (int i = 0; i < 11; i++)
//	{
//		for (int j = 0; j < 20; j++)
//		{
//			int x = (double)i;
//			double y = (double)j;
//			double z = map_info->map[i][j];
////			printf("x : %f, y: %f\n", x, y);
//			rotate(&x, &y, &z);
////			DDA(x, y, x + 1, )
////			printf("x: %f, y: %f\n", x, y);
//			my_mlx_pixel_put(fdf, ceil(x) * 10 + 500, ceil(y) * 10 + 200, 0x00FF0000);
//		}
//	}
//	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
//	mlx_key_hook(fdf->win, esc_close, &fdf);
//	mlx_loop(fdf->mlx);
//}





//static void	bresenham(t_point cur, t_point next, t_fdf *fdf)
//{
//	int x;
//	int y;
//	int dx;
//	int dy;
//
//	x = floor(cur.x);
//	y = floor(cur.y);
//	dx = floor(next.x - cur.x); // w
//	dy = floor(next.y - cur.y); // h
//	// 0 < 기울기 <= 1
//	if (abs(dy) <= abs(dx))
//	{
//		int init = 2 * dy - dx;
//
//		// 각 판별식 공식
//		int D_1 = 2 * dy;
//		int D_2 = 2 * (dy - dx);
//
//		for (int x; x <= next.x; x++)
//		{
//			my_mlx_pixel_put(fdf, x, y, 0x00000000);
//			if (init < 0)
//				init += D_1;
//			else
//			{
//				y++;
//				init += D_2;
//			}
//		}
//	}
//
//	else
//	{
//		int init = 2 * dx - dy;
//
//		int D_1 = 2 * dx;
//		int D_2 = 2 * (dx - dy);
//
//		for (int y; next.y; y++)
//		{
//			my_mlx_pixel_put(fdf, x, y, 0x00000000);
//			if (init < 0)
//				init += D_1;
//			else
//			{
//				x++;
//				init += D_2;
//			}
//		}
//	}
//}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color) {

	char *dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

//static void bresenham(t_point s, t_point f, t_fdf *fdf)
//{
//	t_point	d;
//	t_point	cur;
//
//	cur = f;
//	d.x = abs(s.x - f.x);
//	d.y = abs(s.y - f.y);
//
//
//
//}

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

static void	free_int(int **ret, int i)
{
	while (i)
		free(ret[--i]);
	free(ret);
	return ;
}

int ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

static t_point relocate(t_point point, t_map *map)
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
				bresenham(relocate(init_point(x, y, map_info), map_info), relocate(init_point(x + 1, y, map_info), map_info), fdf);
			if (y != map_info->height - 1)
				bresenham(relocate(init_point(x, y, map_info),map_info), relocate(init_point(x, y + 1, map_info), map_info), fdf);
			x++;
		}
		y++;
	}
	free_int(map_info->map, map_info->height);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, esc_close, &fdf);
	mlx_loop(fdf->mlx);
}