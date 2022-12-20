/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:14 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/19 13:44:34 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void check_eat(t_philo *philo)
{
	if (philo->times_must_eat > 0)
	{
		if((philo)->times_eat < philo->times_must_eat)
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

void is_eating(t_philo *philo)
{
	if (philo->right == NULL)
		{
			if(*philo->is_died == 0)
			{
				pthread_mutex_lock(&philo->m_fork);
				pthread_mutex_lock(&philo->first->m_fork);
				if(*philo->is_died == 0)
					print_action("has taken a fork", current_timestamp(), philo);
				if(*philo->is_died == 0)
					print_action("has taken a fork", current_timestamp(), philo);
				philo->last_eat = current_timestamp();
				if(*philo->is_died == 0)
					print_action("is eating", philo->last_eat, philo);
				if(*philo->is_died == 0)
					check_eat(philo);
				usleep(philo->time_to_eat * 1000);
			}
			pthread_mutex_unlock(&philo->m_fork);
			pthread_mutex_unlock(&philo->first->m_fork);
		}
		else
		{
			if(*philo->is_died == 0)
			{
				pthread_mutex_lock(&philo->m_fork);
				pthread_mutex_lock(&philo->right->m_fork);
				if(*philo->is_died == 0)
					print_action("has taken a fork", current_timestamp(), philo);
				if(*philo->is_died == 0)
					print_action("has taken a fork", current_timestamp(), philo);
				philo->last_eat = current_timestamp();
				if(*philo->is_died == 0)
					print_action("is eating", philo->last_eat, philo);
				if(*philo->is_died == 0)
					check_eat(philo);
				usleep(philo->time_to_eat * 1000);
			}
			pthread_mutex_unlock(&philo->m_fork);
			pthread_mutex_unlock(&philo->right->m_fork);
		}
}
