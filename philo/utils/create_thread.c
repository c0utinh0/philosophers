/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/09 15:57:11 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *thread_func(void *temp)
{
	t_philo *philo = (t_philo *)temp;

	while (1)
	{
		if (philo->right == NULL)
		{
			is_eating(philo);
			is_sleeping(philo->time_to_sleep, philo->id);
			is_thinking(philo->id);
		}
		else
		{
			is_eating(philo);
			is_sleeping(philo->time_to_sleep, philo->id);
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
