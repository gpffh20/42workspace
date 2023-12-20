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

//int	philo_eat(t_info *info, t_philo *philo)
//{
//	if (pthread_mutex_lock(&info->mutex.forks[philo->left_fork]) < 0)
//		return (ERR_MUTEX);
//	if (print_status(info, philo, "has taken a fork") < 0)
//		return (ERR_PHILO);
//	if (pthread_mutex_lock(&info->mutex.forks[philo->right_fork]) < 0)
//		return (ERR_MUTEX);
//	if (print_status(info, philo, "has taken a fork") < 0)
//		return (ERR_PHILO);
//	if (print_status(info, philo, "is eating") < 0)
//		return (ERR_PHILO);
//	philo->last_eat = get_time();
//	if (pthread_mutex_unlock(&info->mutex.forks[philo->left_fork]) < 0)
//		return (ERR_MUTEX);
//	if (pthread_mutex_unlock(&info->mutex.forks[philo->right_fork]) < 0)
//		return (ERR_MUTEX);
//	philo->eat_cnt++;
//	return (SUCCESS);
//}


int	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_act, &philo[i]) < 0)
			return (ERR_THREAD);
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(philo[i].thread, NULL) < 0)
			return (ERR_THREAD);
		i++;
	}
	return (SUCCESS);
}