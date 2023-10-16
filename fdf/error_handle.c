/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:20:07 by eushin            #+#    #+#             */
/*   Updated: 2023/10/13 07:20:10 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	error_handler(char *error_msg)
{
	perror(error_msg);
	return (1);
}

void	invalid_file(char *file_name)
{
	int		len;
	char	*tmp;

	len = ft_strlen(file_name);
	tmp = ft_substr(file_name, len - 4, 4);
	if (ft_strncmp(tmp, ".fdf", 4))
	{
		free(tmp);
		return ;
	}
	free(tmp);
	exit(error_handler("Error: map extension error."));
}
