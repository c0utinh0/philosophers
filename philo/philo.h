/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:59 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/10 20:02:39 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_simulation
{
	pthread_t t_simulation;
	struct s_philo **philos;
	int died;
} t_simulation;

typedef struct s_philo
{
	pthread_t t_id;
	pthread_t t_monitor;	
	pthread_mutex_t fork;
	struct s_philo *first;
	struct s_philo *right;
	struct s_philo *left;
	int *died;
	int id;	
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_must_eat;
	int times_eat;
	long long last_eat;
	long long times_of_death;
} t_philo;

int ft_atoi(char *str);
void create_philos(char **argv, int argc, t_simulation **simulation);
void threads(t_simulation **simulation);
void *thread_simulation(void *temp);
void *thread_monitor(void *temp);
long long current_timestamp(void);
void is_eating(t_philo *philo);
void is_thinking(int philo);
void is_sleeping(int time, int philo);

#endif
