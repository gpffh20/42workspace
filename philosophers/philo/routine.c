/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:45:40 by eushin            #+#    #+#             */
/*   Updated: 2023/12/24 00:45:41 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->mutex.forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->mutex.forks[philo->right_fork]);
}


int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex.forks[philo->left_fork]);
	if (print_state(philo, "has taken a fork\n") == FAIL)
	{
		pthread_mutex_unlock(&philo->info->mutex.forks[philo->left_fork]);
		return (FAIL);
	}
	pthread_mutex_lock(&philo->info->mutex.forks[philo->right_fork]);
	if (print_state(philo, "has taken a fork\n") == FAIL)
	{
		pthread_mutex_unlock(&philo->info->mutex.forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->info->mutex.forks[philo->left_fork]);
		return (FAIL);
	}
	return (SUCCESS);
}

int	eating(t_philo *philo)
{
	long long	last_time;

	if (print_state(philo, "is eating\n") == FAIL)
	{
		put_fork(philo);
		return (FAIL);
	}
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat_time = get_time();
	last_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->last_eat_mutex);
	while (check_is_died(philo) == FALSE && get_time() - last_time < philo->info->time_to_eat)
		usleep(100);
	put_fork(philo);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->info->limit_eat_cnt)
	{
		pthread_mutex_lock(&philo->info->mutex.num_full_philo_mutex);
		philo->info->num_full_philo++;
		pthread_mutex_unlock(&philo->info->mutex.num_full_philo_mutex);
		return (FAIL);
	}
	if (check_is_died(philo) == TRUE)
		return (FAIL);
	return (SUCCESS);
}



int sleeping(t_philo *philo)
{
	long long	last_time;

	if (print_state(philo, "is sleeping\n") == FAIL)
		return (FAIL);
	last_time = get_time();
	while (check_is_died(philo) == FALSE && get_time() - last_time < philo->info->time_to_sleep)
		usleep(200);
	return (SUCCESS);
}

int	thinking(t_philo *philo)
{
	if (print_state(philo, "is thinking\n") == FAIL)
		return (FAIL);
	return (SUCCESS);
}
