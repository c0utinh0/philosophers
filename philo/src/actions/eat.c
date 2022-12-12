/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:14 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 16:45:08 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void is_eating(t_philo *philo)
{
	if (philo->right == NULL)
		{
			if(*philo->died == 0)
			{
				pthread_mutex_lock(&philo->fork);
				pthread_mutex_lock(&philo->first->fork);
				if(*philo->died == 0)
					print_action("has taken a fork", current_timestamp(), philo->id);
				if(*philo->died == 0)
					print_action("has taken a fork", current_timestamp(), philo->id);
				philo->last_eat = current_timestamp();
				if(*philo->died == 0)
					print_action("is eating", philo->last_eat, philo->id);
				usleep(philo->time_to_eat * 1000);
			}
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->first->fork);
		}
		else
		{
			if(*philo->died == 0)
			{
				pthread_mutex_lock(&philo->fork);
				pthread_mutex_lock(&philo->right->fork);
				if(*philo->died == 0)
					print_action("has taken a fork", current_timestamp(), philo->id);
				if(*philo->died == 0)
					print_action("has taken a fork", current_timestamp(), philo->id);
				philo->last_eat = current_timestamp();
				if(*philo->died == 0)
					print_action("is eating", philo->last_eat, philo->id);
				usleep(philo->time_to_eat * 1000);
			}
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->right->fork);
		}
}
