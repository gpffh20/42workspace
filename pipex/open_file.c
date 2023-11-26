/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:30:03 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:30:04 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_args *args, t_fds *fds)
{
	fds->infile_fd = open(args->av[1], O_RDONLY);
	fds->outfile_fd = open(args->av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fds->infile_fd < 0 || fds->outfile_fd < 0)
		return (error_handle(4));
}
