/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:37:01 by eushin            #+#    #+#             */
/*   Updated: 2023/12/24 00:54:08 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex.forks[philo->left_fork]);
	print_state(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->info->mutex.forks[philo->left_fork]);
	while (get_ms_time() - philo->info->start_time < philo->info->time_to_die)
		usleep(500);
	print_died(philo);
	return (SUCCESS);
}

static void	*philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat_time = get_ms_time();
	pthread_mutex_unlock(&philo->last_eat_mutex);
	if (philo->id % 2 == 0)
	{
		if (philo->info->time_to_die < \
		philo->info->time_to_eat + philo->info->time_to_sleep)
			usleep(philo->info->time_to_die * 1000 / 2);
		else
			usleep(philo->info->time_to_eat * 1000 / 2);
	}
	while (check_is_died(philo) == FALSE)
	{
		if (take_forks(philo) == FAIL || eating(philo) == FAIL)
			return (NULL);
		if (sleeping(philo) == FAIL)
			return (NULL);
		if (thinking(philo) == FAIL)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

int	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	info->start_time = get_ms_time();
	if (info->num_philo == 1)
		return (one_philo(philo));
	while (i < info->num_philo)
	{
		if (pthread_create(&philo[i].thread_id, NULL, \
		philo_start, &philo[i]) == FAIL)
			return (print_error(ERR_PHILO, info, philo));
		i++;
	}
	usleep(500);
	monitoring(info, philo);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(philo[i].thread_id, NULL) == FAIL)
			return (print_error(ERR_PHILO, info, philo));
		i++;
	}
	return (SUCCESS);
}
