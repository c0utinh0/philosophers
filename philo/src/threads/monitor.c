/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:16 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/06 10:08:47 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	move_list(t_philo *philo)
{
	if (philo->right == NULL && check_is_died(philo))
		philo = philo->first;
	else if (philo->right != NULL && check_is_died(philo))
		philo = philo->right;
	usleep(100);
}

static void	monitor(t_philo *philo)
{
	*(philo)->is_died = 1;
	pthread_mutex_lock(&(*philo->m_print));
	printf(" %lldms %d %s\n", interval_timestamp(philo->is_born),
		philo->id, "is died");
	pthread_mutex_unlock(&(*philo->m_print));
	pthread_mutex_unlock(&(*philo->m_died));
}

void	*thread_monitor(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	while (philo != NULL)
	{
		pthread_mutex_lock(&(*philo->m_died));
		if (*(philo)->is_full >= philo->nop)
		{
			*(philo)->is_died = 1;
			pthread_mutex_unlock(&(*philo->m_died));
			break ;
		}
		else if ((current_timestamp() - philo->last_eat) > philo->time_to_die)
		{
			monitor(philo);
			break ;
		}
		pthread_mutex_unlock(&(*philo->m_died));
		move_list(philo);
	}
	return (NULL);
}
