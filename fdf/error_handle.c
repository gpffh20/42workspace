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
	int	 len;

	len = ft_strlen(file_name);
	if (ft_strncmp(ft_substr(file_name, len - 4, 4), ".fdf", 4))
		return ;
	exit(error_handler("Error: map extension error."));
}
