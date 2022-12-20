/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:59 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 16:43:13 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_simulation
{
	pthread_t		t_simulation;
	struct s_philo	**philos;
	struct s_philo	*philos_free;
	int				is_died;
	int				is_full;
	int				s_argc;
	char			**s_argv;
}	t_simulation;

typedef struct s_philo
{
	pthread_t		t_id;
	pthread_t		t_monitor;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	m_full;
	struct s_philo	*first;
	struct s_philo	*right;
	struct s_philo	*left;
	int				*is_died;
	int				*is_full;
	long long		is_born;
	int				philo_is_full;
	int				id;
	int				nop;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				times_eat;
	long long		last_eat;
	long long		times_of_death;
}	t_philo;

int			ft_atoi(char *str);
long int	ft_atoi_check(const char *nptr);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			check_args(int argc, char **argv);
void		create_philos(char **argv, int argc, t_simulation **simulation);
void		threads(t_simulation **simulation);
void		*thread_simulation(void *temp);
void		*thread_monitor(void *temp);
long long	current_timestamp(void);
long long	interval_timestamp(long long is_born);
void		is_eating(t_philo *philo);
void		is_thinking(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		print_action(char *msg, t_philo *philo);
void		stop_simulation(t_simulation **simulation);

#endif
