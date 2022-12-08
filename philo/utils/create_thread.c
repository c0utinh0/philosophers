/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/08 19:26:04 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void is_sleep(int time, int philo)
{
	printf("%lld %d is sleeping\n", current_timestamp(), philo);
	usleep(time * 1000);
}

void is_thinking(int philo)
{
	printf("%lld %d is thinking\n", current_timestamp(), philo);
}

void *thread_func(void *temp)
{
	t_philo *philo = (t_philo *)temp;

	while (1)
	{
		if (philo->right == NULL)
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->first->fork);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d is eating\n", current_timestamp(), philo->id);
			usleep(100 * 1000);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->first->fork);
			is_sleep(100, philo->id);
			is_thinking(philo->id);
		}
		else
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->right->fork);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d is eating\n", current_timestamp(), philo->id);
			usleep(100 * 1000);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->right->fork);
			is_sleep(100, philo->id);
			is_thinking(philo->id);
		}
	}
	return NULL;
}

void create_thread(t_philo **philos)
{
	t_philo *philo;

	philo = *philos;
	while (philo != NULL)
	{
		pthread_create(&philo->t_id, NULL, thread_func, (void *)philo);
		philo = philo->right;
	}
	philo = *philos;
	while (philo != NULL)
	{
		pthread_join(philo->t_id, NULL);
		philo = philo->right;
	}
}
