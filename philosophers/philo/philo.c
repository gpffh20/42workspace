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

void	print_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex.print_mutex);
	if (philo->info->mutex.is_print == FALSE)
	{
		printf("%lld %d %s", get_time() - philo->info->start_time, philo->id, "died\n");
		philo->info->mutex.is_print = TRUE;
	}
	pthread_mutex_unlock(&philo->info->mutex.print_mutex);
	return ;
}


int	print_state(t_philo *philo, char *msg)
{
	int ret;

	ret = SUCCESS;
	pthread_mutex_lock(&philo->info->mutex.print_mutex);
	if (philo->info->mutex.is_print == FALSE)
		printf("%lld %d %s", get_time() - philo->info->start_time, philo->id, msg);
	else
		ret = FAIL;
	pthread_mutex_unlock(&philo->info->mutex.print_mutex);
	return (ret);
}

void	monitoring(t_info *info, t_philo *philo)
{
	int		idx;

	idx = 0;
	while (TRUE)
	{
		pthread_mutex_lock(&info->mutex.num_full_philo_mutex);
		if (info->num_full_philo == info->num_philo)
		{
			pthread_mutex_unlock(&info->mutex.num_full_philo_mutex);
			return ;
		}
		pthread_mutex_lock(&philo[idx].last_eat_mutex);
		if (get_time() - philo[idx].last_eat_time > info->time_to_die)
		{
			pthread_mutex_lock(&info->mutex.is_died_mutex);
			info->mutex.is_died = TRUE;
			pthread_mutex_unlock(&info->mutex.is_died_mutex);
			pthread_mutex_unlock(&philo[idx].last_eat_mutex);
			print_died(&philo[idx]);
			return ;
		}
		pthread_mutex_unlock(&philo[idx].last_eat_mutex);
		idx++;
		idx %= info->num_philo;
	}
}

int	check_is_died(t_philo *philo)
{
	int	res;

	res = FALSE;
	pthread_mutex_lock(&philo->info->mutex.is_died_mutex);
	if (philo->info->mutex.is_died == TRUE)
		res = TRUE;
	pthread_mutex_unlock(&philo->info->mutex.is_died_mutex);
	return (res);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


int	eating(t_philo *philo)
{
	long long	last_time;

	if (print_state(philo, "is eating\n") == FAIL)
	{
		pthread_mutex_unlock(&philo->info->mutex.forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->mutex.forks[philo->right_fork]);
		return (FAIL);
	}
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat_time = get_time();
	last_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->last_eat_mutex);

	while (check_is_died(philo) == FALSE && get_time() - last_time < philo->info->time_to_eat)
		usleep(200);

	pthread_mutex_unlock(&philo->info->mutex.forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->mutex.forks[philo->right_fork]);

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

int sleeping(t_philo *philo)
{
	long long	last_time;

	if (print_state(philo, "is sleeping\n") == FAIL)
		return (FAIL);
	last_time = get_time();
	while (check_is_died(philo) == FALSE && get_time() - last_time < philo->info->time_to_sleep)
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
	while (check_is_died(philo) == FALSE)
	{
		if (take_forks(philo) == FAIL || eating(philo) == FAIL)
			return (NULL);
		if (sleeping(philo) == FAIL)
			return (NULL);
		if (thinking(philo) == FAIL)
			return (NULL);
		usleep(200);
	}
	return (NULL);
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
	usleep(1000);
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