/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:40:34 by eushin            #+#    #+#             */
/*   Updated: 2023/12/20 17:40:37 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_pos_int(char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || av[i][j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int init_mutex(t_info *info)
{
	int i;

	i = 0;
	memset(&info->mutex, 0, sizeof(t_mutex));
	if (pthread_mutex_init(&info->mutex.print_mutex, NULL) < 0)
		return (print_error(ERR_MUTEX));
	info->mutex.is_dead = FALSE;
	if (pthread_mutex_init(&info->mutex.is_dead_mutex, NULL) < 0)
		return (print_error(ERR_MUTEX));
	info->mutex.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->mutex.forks)
		return (print_error(ERR_MALLOC));
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->mutex.forks[i], NULL) < 0)
		{
			free(info->mutex.forks);
			return (print_error(ERR_MUTEX));
		}
		i++;
	}
	return (0);
}

int	init_info(t_info *info, int ac, char *av[])
{
	memset(info, 0, sizeof(t_info));
	if (!check_pos_int(av))
		return (print_error(ERR_ARGV));
	info->num_philo = ft_atoi(av[1]);
	if (info->num_philo < 1)
		return (print_error(ERR_ARGV));
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->limit_eat_cnt = -1;
	if (ac == 6)
		info->limit_eat_cnt = ft_atoi(av[5]);
	if (init_mutex(info) < 0)
		return (-1);
	return (0);
}

t_philo *init_philo(t_info *info, int *errno)
{
	int i;
	t_philo *philo;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (!philo)
	{
		*errno = ERR_MALLOC;
		return (NULL);
	}
	while (i < info->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_cnt = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % info->num_philo;
		philo[i].info = info;
		philo[i].last_eat_time = info->start_time;
		if (pthread_mutex_init(&philo[i].last_eat_mutex, NULL) < 0)
		{
			free(philo);
			*errno = ERR_MUTEX;
			return (NULL);
		}
		i++;
	}
	return (philo);
}
