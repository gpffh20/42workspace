/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:29:50 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:29:51 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	*tmp;

	if (!envp)
		error_handle(6);
	i = 0;
	tmp = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tmp = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (ft_split(tmp, ':'));
}
