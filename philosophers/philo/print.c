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