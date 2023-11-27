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

void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	args;

	if (ac != 5)
		error_handle(1);
	args.envp = envp;
	init_args(&args, av);
	execute(&args, av);
	ft_free(args.path);
	ft_free(args.arg1);
	ft_free(args.arg2);
}
