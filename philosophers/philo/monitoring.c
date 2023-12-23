/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:45:15 by eushin            #+#    #+#             */
/*   Updated: 2023/12/24 00:45:16 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

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
