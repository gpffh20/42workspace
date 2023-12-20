/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:37:12 by eushin            #+#    #+#             */
/*   Updated: 2023/12/01 01:37:13 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

enum	e_errno
{
	SUCCESS,
	ERR_ARGC,
	ERR_ARGV,
	ERR_MALLOC,
	ERR_MUTEX,
	ERR_THREAD,
	ERR_TIME,
	ERR_PHILO
};

typedef struct s_mutex
{
	pthread_mutex_t	print_mutex;
	int				is_dead;
	pthread_mutex_t	is_dead_mutex;
	pthread_mutex_t	*forks;
}	t_mutex;

typedef struct s_info
{
	int			num_philo;
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
	pthread_t		thread;
	long long		last_eat_time;
	pthread_mutex_t	last_eat_mutex;
}	t_philo;

int		ft_atoi(const char *str);
int		ft_isdigit(char c);

int		print_error(int errno);

t_philo	*init_philo(t_info *info, int *errno);
int		init_info(t_info *info, int ac, char *av[]);
int		init_mutex(t_info *info);


#endif