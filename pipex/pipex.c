/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:30:10 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:30:11 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	args;

	if (ac != 5)
		error_handle(1);
	args.envp = envp;
	init_args(&args, av);
//	if (pipe(args.pipe) < 0)
//		error_handle(2);
	execute(&args, av);
}