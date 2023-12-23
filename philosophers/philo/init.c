/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:40:34 by eushin            #+#    #+#             */
/*   Updated: 2023/12/24 03:18:19 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_numeric(char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	memset(&info->mutex, 0, sizeof(t_mutex));
	info->mutex.is_print = FALSE;
	if (pthread_mutex_init(&info->mutex.print_mutex, NULL) == FAIL)
		return (print_error(ERR_MUTEX, NULL, NULL));
	info->mutex.is_died = FALSE;
	if (pthread_mutex_init(&info->mutex.is_died_mutex, NULL) == FAIL)
		return (print_error(ERR_MUTEX, NULL, NULL));
	info->mutex.forks = (pthread_mutex_t *)malloc \
	(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->mutex.forks)
		return (print_error(ERR_MALLOC, NULL, NULL));
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->mutex.forks[i], NULL) == FAIL)
			return (print_error(ERR_MUTEX, info, NULL));
		i++;
	}
	return (SUCCESS);
}

int	init_info(t_info *info, int ac, char *av[])
{
	memset(info, 0, sizeof(t_info));
	if (check_numeric(av) == FALSE)
		return (print_error(ERR_ARGV, NULL, NULL));
	info->num_philo = ft_atoi(av[1]);
	if (info->num_philo < 1)
		return (print_error(ERR_ARGV, NULL, NULL));
	info->num_full_philo = 0;
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->limit_eat_cnt = -1;
	if (ac == 6)
		info->limit_eat_cnt = ft_atoi(av[5]);
	if (init_mutex(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	*philo = (t_philo *) malloc(sizeof(t_philo) * info->num_philo);
	if (*philo == NULL)
		return (ERR_MALLOC);
	while (i < info->num_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % info->num_philo;
		(*philo)[i].info = info;
		(*philo)[i].last_eat_time = info->start_time;
		if (pthread_mutex_init(&(*philo)[i].last_eat_mutex, NULL) == FAIL)
		{
			free(*philo);
			return (ERR_MUTEX);
		}
		i++;
	}
	return (SUCCESS);
}
