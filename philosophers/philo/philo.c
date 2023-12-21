/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:37:01 by eushin            #+#    #+#             */
/*   Updated: 2023/12/01 01:37:02 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	print_state(t_philo *philo, char *msg)
{
	long long	time_taken;

	pthread_mutex_lock(&philo->info->mutex.print_mutex);
	if (philo->info->mutex.is_dead == TRUE)
	{
		pthread_mutex_unlock(&philo->info->mutex.print_mutex);
		return (FAIL);
	}
	time_taken = get_time() - philo->info->start_time;
	printf("%lld %d %s", time_taken, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->info->mutex.print_mutex);
	return (SUCCESS);

}

int	eating(t_philo *philo)
{
	if (print_state(philo, "is eating\n") == FAIL)
		return (FAIL);
	philo->last_eat_time = get_time();
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->info->limit_eat_cnt)
		philo->info->num_full_philo++;
	if (philo->info->num_full_philo == philo->info->num_philo)
		philo->info->mutex.is_dead = TRUE;
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->info->mutex.forks[philo->id]);
	pthread_mutex_unlock(&philo->info->mutex.forks[(philo->id + 1) \
		% philo->info->num_philo]);
	return (SUCCESS);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex.forks[philo->id]);
	pthread_mutex_lock(&philo->info->mutex.forks[(philo->id + 1) \
		% philo->info->num_philo]);
	if (print_state(philo, "has taken a fork\n") == FAIL)
	{
		pthread_mutex_unlock(&philo->info->mutex.forks[philo->id]);
		pthread_mutex_unlock(&philo->info->mutex.forks[(philo->id + 1) \
		% philo->info->num_philo]);
		return (FAIL);
	}
	return (SUCCESS);
}

int sleeping(t_philo *philo)
{
	if (print_state(philo, "is sleeping\n") == FAIL)
		return (FAIL);
	usleep(philo->info->time_to_sleep * 1000);
	return (SUCCESS);
}

int	thinking(t_philo *philo)
{
	if (print_state(philo, "is thinking\n") == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	*philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat_time = get_time();
	if (philo->id % 2 == 0)
	{
		if (philo->info->time_to_die < \
		philo->info->time_to_eat + philo->info->time_to_sleep)
			usleep(philo->info->time_to_die * 1000 / 2);
		else
			usleep(philo->info->time_to_eat * 1000 / 2);
	}
	while (TRUE)
	{
		if (take_forks(philo) == FAIL)
			return (NULL);
		if (eating(philo) == FAIL)
			return (NULL);
		if (sleeping(philo) == FAIL)
			return (NULL);
		if (thinking(philo) == FAIL)
			return (NULL);
	}
}


int	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->num_philo)
	{
		if (pthread_create(&philo[i].thread_id, NULL, \
		philo_start, &philo[i]) == FAIL)
			return (print_error(ERR_PHILO, info, philo));
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(philo[i].thread_id, NULL) == FAIL)
			return (print_error(ERR_PHILO, info, philo));
		i++;
	}
	return (SUCCESS);
}