/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:14 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/09 15:53:53 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void is_eating(t_philo *philo)
{
	if (philo->right == NULL)
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->first->fork);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d is eating\n", current_timestamp(), philo->id);
			usleep(philo->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->first->fork);
		}
		else
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->right->fork);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d has taken a fork\n", current_timestamp(), philo->id);
			printf("%lld %d is eating\n", current_timestamp(), philo->id);
			usleep(philo->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->right->fork);
		}
}