/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:14 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/13 15:50:39 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void is_eating(t_philo *philo)
{
	if (philo->right == NULL)
		{
			if(*philo->is_died == 0)
			{
				pthread_mutex_lock(&philo->m_fork);
				pthread_mutex_lock(&philo->first->m_fork);
				if(*philo->is_died == 0)
					print_action("has taken a fork", current_timestamp(), philo->id);
				if(*philo->is_died == 0)
					print_action("has taken a fork", current_timestamp(), philo->id);
				philo->last_eat = current_timestamp();
				if(*philo->is_died == 0)
					print_action("is eating", philo->last_eat, philo->id);
				usleep(philo->time_to_eat * 1000);
				philo->times_eat++;
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
					print_action("has taken a fork", current_timestamp(), philo->id);
				if(*philo->is_died == 0)
					print_action("has taken a fork", current_timestamp(), philo->id);
				philo->last_eat = current_timestamp();
				if(*philo->is_died == 0)
					print_action("is eating", philo->last_eat, philo->id);
				usleep(philo->time_to_eat * 1000);
				philo->times_eat++;
			}
			pthread_mutex_unlock(&philo->m_fork);
			pthread_mutex_unlock(&philo->right->m_fork);
		}
}
