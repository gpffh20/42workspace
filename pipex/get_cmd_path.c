/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:29:50 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:29:51 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*get_cmd_path(char *cmd, char **path)
{
	int i;
	char *cmd_path;
	char *cmd_tmp;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	cmd_path = ft_strjoin("/", cmd);
	while (path[i])
	{
		cmd_tmp = ft_strjoin(path[i], cmd_path);
		if (access(cmd_tmp, X_OK) == 0)
		{
			free(cmd_path);
			return (cmd_tmp);
		}
		free(cmd_tmp);
		i++;
	}
	free (cmd_path);
	return (NULL);
}
