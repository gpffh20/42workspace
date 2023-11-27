/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:29:20 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:29:23 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handle(int errnum)
{
	ft_putstr_fd("pipex: ", 2);
	if (errnum == 1)
		ft_putstr_fd("Number of Argument Error!\n", 2);
	else if (errnum == 2)
		ft_putstr_fd(strerror(errno), 2);
	else if (errnum == 3)
		ft_putstr_fd(strerror(errno),2);
	else if (errnum == 4)
		ft_putstr_fd(strerror(errno), 2);
	else if (errnum == 5)
		ft_putstr_fd(strerror(errno), 2);
	else if (errnum == 6)
		ft_putstr_fd(strerror(errno), 2);
	else if (errnum == 7)
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
