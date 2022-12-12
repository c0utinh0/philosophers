/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:14 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 15:29:28 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void is_eating(t_philo *philo)
{
	if (philo->right == NULL)
	{
		if (*(philo)->died == 0)
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->first->fork);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
		}
		if (*(philo)->died == 0)
		{
			philo->last_eat = current_timestamp();
			printf("%lld %d is eating\n", philo->last_eat, philo->id);
			usleep(philo->time_to_eat * 1000);
		}
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->first->fork);
	}
	else
	{
		if (*(philo)->died == 0)
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->right->fork);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
		}
		if (*(philo)->died == 0)
		{
			philo->last_eat = current_timestamp();
			printf("%lld %d is eating\n", philo->last_eat, philo->id);
			usleep(philo->time_to_eat * 1000);
		}
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->right->fork);
	}
}
