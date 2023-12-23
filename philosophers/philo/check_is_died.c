#include "philo.h"

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
