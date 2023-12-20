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

int	print_error(int errno)
{
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
	return (-1);
}



int main(int ac, char *av[])
{
	t_info	info;
	t_philo	*philo;
	int		errno;

	errno = SUCCESS;
	if (ac < 5 || ac > 6)
		return (print_error(ERR_ARGC));
	if (init_info(&info, ac, av) < 0)
		return (-1);
	philo = init_philo(&info, &errno);
	if (errno != SUCCESS)
		return (print_error(errno));
}
