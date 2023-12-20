/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:12:42 by eushin            #+#    #+#             */
/*   Updated: 2023/12/20 16:12:43 by eushin           ###   ########.fr       */
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
//	else if (errno == ERR_THREAD)
//		printf("Error: Thread failed\n");
//	else if (errno == ERR_TIME)
//		printf("Error: Time failed\n");
//	else if (errno == ERR_PHILO)
//		printf("Error: Philo failed\n");
	return (FAIL);
}




int main(int ac, char *av[])
{
	int		errno;
	t_info	info;
	t_philo	*philo;

	errno = SUCCESS;
	if (ac < 5 || ac > 6)
		return (print_error(ERR_ARGC, NULL, NULL));
	if (init_info(&info, ac, av) == FAIL)
		return (FAIL);
	errno = init_philo(&philo, &info);
	if (errno != SUCCESS)
		return (print_error(errno, &info, NULL));
	(void)philo;
//	if (philosopher(&info, philo, &errno) == FAIL)
//		return (print_error(errno));
}
