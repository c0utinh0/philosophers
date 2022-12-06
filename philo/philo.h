/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:59 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/06 16:27:52 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	pthread_t		t_id;
	int				id;
	int				fork;
	struct s_philo	*right;
	struct s_philo	*left;
}	t_philo;

typedef struct s_core
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	t_philo	*philo_list;
}	t_core;

void	check_args(int argc, char **argv, t_core *core);
int	ft_atoi(char	*str);
void	create_philo_list(t_core **core);
void	create_thread(t_core **core);
void    *thread_func(void  *temp);
long long current_timestamp(void);

#endif
