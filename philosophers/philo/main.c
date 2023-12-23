/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:12:42 by eushin            #+#    #+#             */
/*   Updated: 2023/12/24 00:52:01 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	int		errno;
	t_info	info;
	t_philo	*philo;

	if (ac < 5 || ac > 6)
		return (print_error(ERR_ARGC, NULL, NULL));
	if (init_info(&info, ac, av) == FAIL)
		return (FAIL);
	errno = init_philo(&philo, &info);
	if (errno != SUCCESS)
		return (print_error(errno, &info, NULL));
	if (philosopher(&info, philo) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
