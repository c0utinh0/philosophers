/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:26 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/02 20:49:14 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	one_philo_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_fork);
	if (check_is_died(philo))
		print_action("has taken a fork", philo);
	philo->last_eat = current_timestamp();
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->m_fork);
}

void	*thread_simulation(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->id % 2 == 0)
		usleep(200);
	if (philo->nop == 1)
		one_philo_simulation(philo);
	else
	{
		while (check_is_died(philo))
		{
			if (check_is_died(philo))
				is_eating(philo);
			if (check_is_died(philo))
				is_sleeping(philo);
			if (*philo->is_died == 0)
			{
				is_thinking(philo);
			}
			pthread_mutex_unlock(&(*philo->m_died));
		}
	}
	return (NULL);
}
