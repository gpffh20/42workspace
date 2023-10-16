/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:19:59 by eushin            #+#    #+#             */
/*   Updated: 2023/10/16 17:58:23 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(int ac, char *av[])
{
	t_map	map_info;
	t_fdf	fdf;

	if (ac == 2)
	{
		invalid_file(av[1]);
		read_map(av[1], &map_info);
		my_mlx(&fdf, av[1]);
		draw(&map_info, &fdf);
		fdf.map = &map_info;
		mlx_key_hook(fdf.win, esc_close, &fdf);
		mlx_hook(fdf.win, 17, 0, mouse_close, &fdf);
		mlx_loop(fdf.mlx);
	}
	exit(error_handler("Error: argument count error."));
}
