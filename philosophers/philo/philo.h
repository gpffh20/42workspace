/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:37:12 by eushin            #+#    #+#             */
/*   Updated: 2023/12/24 00:54:36 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

enum	e_errno
{
	FAIL = -1,
	SUCCESS,
	ERR_ARGC,
	ERR_ARGV,
	ERR_MALLOC,
	ERR_MUTEX,
	ERR_PHILO,
};

typedef struct s_mutex
{
	pthread_mutex_t	num_full_philo_mutex;
	int				is_print;
	pthread_mutex_t	print_mutex;
	int				is_died;
	pthread_mutex_t	is_died_mutex;
	pthread_mutex_t	*forks;
}	t_mutex;

typedef struct s_info
{
	int			num_philo;
	int			num_full_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			limit_eat_cnt;
	long long	start_time;
	t_mutex		mutex;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	int				left_fork;
	int				right_fork;
	t_info			*info;
	pthread_t		thread_id;
	long long		last_eat_time;
	pthread_mutex_t	last_eat_mutex;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(char c);
int			print_error(int errno, t_info *info, t_philo *philo);
int			put_fork(t_philo *philo);
int			eating(t_philo *philo);
int			take_forks(t_philo *philo);
int			sleeping(t_philo *philo);
int			thinking(t_philo *philo);
int			init_philo(t_philo **philo, t_info *info);
int			init_info(t_info *info, int ac, char *av[]);
int			init_mutex(t_info *info);
int			philosopher(t_info *info, t_philo *philo);
void		monitoring(t_info *info, t_philo *philo);
void		print_died(t_philo *philo);
int			print_state(t_philo *philo, char *msg);
long long	get_time(void);
int			check_is_died(t_philo *philo);
#endif
