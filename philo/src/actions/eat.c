/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:14 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/06 10:05:50 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	check_eat(t_philo *philo)
{
	if (philo->times_must_eat > 0)
	{
		if ((philo)->times_eat < philo->times_must_eat)
			philo->times_eat++;
		if ((philo)->times_eat >= philo->times_must_eat)
		{
			pthread_mutex_lock(&philo->m_full);
			*philo->is_full = *philo->is_full + 1;
			philo->philo_is_full = 1;
			pthread_mutex_unlock(&philo->m_full);
		}
	}
	else
		philo->times_eat++;
}

static void	last_philo(t_philo *philo)
{
	if (check_is_died(philo))
	{
		pthread_mutex_lock(&philo->m_fork);
		pthread_mutex_lock(&philo->first->m_fork);
		if (check_is_died(philo))
			print_action("has taken a fork", philo);
		if (check_is_died(philo))
			print_action("has taken a fork", philo);
		philo->last_eat = current_timestamp();
		if (check_is_died(philo))
			print_action("is eating", philo);
		if (check_is_died(philo))
			check_eat(philo);
		usleep(philo->time_to_eat * 1000);
	}
	pthread_mutex_unlock(&philo->first->m_fork);
	pthread_mutex_unlock(&philo->m_fork);
}

static void	normal_philo(t_philo *philo)
{
	if (check_is_died(philo))
	{
		pthread_mutex_lock(&philo->m_fork);
		pthread_mutex_lock(&philo->right->m_fork);
		if (check_is_died(philo))
			print_action("has taken a fork", philo);
		if (check_is_died(philo))
			print_action("has taken a fork", philo);
		philo->last_eat = current_timestamp();
		if (check_is_died(philo))
			print_action("is eating", philo);
		if (check_is_died(philo))
			check_eat(philo);
		usleep(philo->time_to_eat * 1000);
	}
	pthread_mutex_unlock(&philo->right->m_fork);
	pthread_mutex_unlock(&philo->m_fork);
}

void	is_eating(t_philo *philo)
{
	if (philo->right == NULL)
		last_philo(philo);
	else
		normal_philo(philo);
}
