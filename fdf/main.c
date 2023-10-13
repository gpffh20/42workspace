/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:19:59 by eushin            #+#    #+#             */
/*   Updated: 2023/10/13 07:20:02 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char *av[])
{
	t_map map_info;
	t_fdf fdf;

	if (ac == 2)
	{
		invalid_file(av[1]);
		read_map(av[1], &map_info);
		my_mlx(&fdf, av[1]);
		draw(&map_info, &fdf);
	}
	exit(error_handler("Error: argument count error."));
}

//int	main(int ac, char *av[])
//{
//	int		fd;
//	double	**dmap;
//	t_data	img;
//	t_vars	vars;
//
//	if (ac != 2) {
//		exit(error_handle("Error: 인자 수 에러"));
//	}
//	right_file(av[1]);
//	fd = open(av[1], O_RDONLY);
//	if (fd < 0) {
//		exit(error_handle("Error: open 에러"));
//	}
//	dmap = read_map(fd, 0);
//	for (int i = 0; i < 11; i++)
//	{
//		for (int j = 0; j < 20; j++)
//		{
//			double x = (double)i;
//			double y = (double)j;
//			double z = dmap[i][j];
////			printf("x : %f, y: %f\n", x, y);
//			rotate(&x, &y, &z);
//			DDA(x, y, x + 1, )
////			printf("x: %f, y: %f\n", x, y);
////			my_mlx_pixel_put(&img, ceil(x) * 10 + 500, ceil(y) * 10 + 200, 0x00FF0000);
//		}
//	}
//	close(fd);
//	ft_mlx(&vars, &img, av[1]);
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
//	mlx_key_hook(vars.win, esc_close, &vars);
//	mlx_loop(vars.mlx);
//
//	printf("%f", dmap[0][0]);
//	return (0);
//}
