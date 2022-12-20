/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:26 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 15:01:19 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	one_philo_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_fork);
	if (*philo->is_died == 0)
		print_action("has taken a fork", current_timestamp(), philo);
	philo->last_eat = current_timestamp();
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->m_fork);
}

void	*thread_simulation(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->nop == 1)
		one_philo_simulation(philo);
	else
		while (*(philo)->is_died == 0)
		{
			if (*philo->is_died == 0)
				is_eating(philo);
			if (*philo->is_died == 0)
				is_sleeping(philo);
			if (*philo->is_died == 0)
				is_thinking(philo);
		}
	return (NULL);
}
