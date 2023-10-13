/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:47:22 by eushin            #+#    #+#             */
/*   Updated: 2023/10/10 15:47:24 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x
			* (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//int	esc_close(int keycode, t_fdf *fdf)
//{
//	if (keycode == 53)
//	{
//		mlx_destroy_window(fdf->mlx, fdf->win);
//		exit(0);
//	}
//	return (0);
//}

void	my_mlx(t_fdf *fdf, char *file_name)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1500, 850, file_name);
	fdf->img = mlx_new_image(fdf->mlx, 1500, 850);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),&(fdf->line_length), &(fdf->endian));
}