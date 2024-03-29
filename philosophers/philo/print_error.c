/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:46:20 by eushin            #+#    #+#             */
/*   Updated: 2023/12/24 00:46:21 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(int errno, t_info *info, t_philo *philo)
{
	if (info != NULL)
		free(info->mutex.forks);
	if (philo != NULL)
		free(philo);
	if (errno == ERR_ARGC)
		printf("Error: Wrong number of arguments\n");
	else if (errno == ERR_ARGV)
		printf("Error: Invalid argument\n");
	else if (errno == ERR_MALLOC)
		printf("Error: Malloc failed\n");
	else if (errno == ERR_MUTEX)
		printf("Error: Mutex failed\n");
	else if (errno == ERR_PHILO)
		printf("Error: Philo failed\n");
	return (FAIL);
}
