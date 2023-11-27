/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:29:57 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:29:58 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_args(t_pipex *args, char **av)
{
	args->path = get_path(args->envp);
	args->arg1 = ft_split(av[2], ' ');
//	for (int i = 0; i < 3; i++)
//		ft_printf("args: %s\n", args->arg1[i]);
	args->arg2 = ft_split(av[3], ' ');
}
