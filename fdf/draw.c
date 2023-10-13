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

int	esc_close(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

void draw(t_map *map_info, t_fdf *fdf)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			double x = (double)i;
			double y = (double)j;
			double z = map_info->map[i][j];
//			printf("x : %f, y: %f\n", x, y);
			rotate(&x, &y, &z);
//			DDA(x, y, x + 1, )
//			printf("x: %f, y: %f\n", x, y);
			my_mlx_pixel_put(fdf, ceil(x) * 10 + 500, ceil(y) * 10 + 200, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, esc_close, &fdf);
	mlx_loop(fdf->mlx);
}

//void	set_Pixel(double x, double y)
//{
//	my_mlx_pixel_put(&fdf, ceil(x) * 10 + 500, ceil(y) * 10 + 200, 0x00FF0000);
//	return ();
//}


//static t_point init_point(int x, int y, t_map *map_info)
//{
//	t_point	point;
//
//	point.x = x;
//	point.y = y;
//	point.z = map_info->map[x][y];
//	return (point);
//}
//
////void	DDA(int x1, int y1, int x2, int y2)
//void	DDA(t_point *cur, t_point *next, t_fdf *fdf)
//{
//	// x, y축의 증분
//	int	dx;
//	int	dy;
//
//	dx = next->x - cur->x;
//	dy = next->y - next->y;
//	// 총 칠해야 할 픽셀의 가로(y의 경우 세로) 길이
//	int steps;
//	// 시작점 지정
//	double x = cur->x, y = cur->y;
//
//	float x_incre, y_incre;
//
//	if(fabs(dx) > fabs(dy))
//		steps = fabs(dx);
//	else
//		steps = fabs(dy);
//
//	// step가 하나 증가할 때 x, y 좌표가 얼마나 증가할지 지정해준다
//	x_incre = dx / steps;
//	y_incre = dy / steps;
//
//	// 시작 좌표 x(=x1), y(=y1)을 칠해준다
//	set_Pixel(round(x), round(y));
//
//	for(int i = 0; i < steps; i++){
//		x += x_incre;
//		y += y_incre;
//
//		set_Pixel(round(x), round(y));
//	}
//}
//
//void	draw(t_map *map_info, t_fdf *fdf)
//{
//	int	x;
//	int	y;
//
//	y = 0;
//	while (y < map_info->height)
//	{
//		x = 0;
//		while (x < map_info->width)
//		{
//			if (x != map_info->width -1)
//				DDA(iso(init_point(x, y, map_info)), iso(init_point(x + 1, y, map_info)), fdf);
//		}
//	}
//
//}