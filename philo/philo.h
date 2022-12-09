/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:59 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/09 17:54:17 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
#include <sys/time.h>

typedef struct s_monitor
{
	pthread_t t_monitor;
	struct s_philo	**philos;
	int died;
}	t_monitor;

typedef struct s_philo
{
	pthread_t		t_id;
	int				id;
	pthread_mutex_t				fork;
	struct s_philo	*first;
	struct s_philo	*right;
	struct s_philo	*left;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
	int	times_eat;
	long long last_eat;
	int *died;
}	t_philo;

int	ft_atoi(char	*str);
void	create_philos(t_philo **philos, char **argv, int argc, t_monitor *monitor);
void	threads(t_philo **philos);
void    *simulation(void  *philo);
long long current_timestamp(void);
void is_eating(t_philo *philo);
void is_thinking(int philo);
void is_sleeping(int time, int philo);

#endif
