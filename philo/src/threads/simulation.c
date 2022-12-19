/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:26 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/14 19:58:36 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void *thread_simulation(void *temp)
{
	t_philo *philo = (t_philo *)temp;

	if (philo->times_must_eat > 0 )
	{
		while (*(philo)->is_died == 0)
		{	
			if(*philo->is_died == 0)
				is_eating(philo);
			if(*philo->is_died == 0)
				is_sleeping(philo->time_to_sleep, philo->id);
			if(*philo->is_died == 0 && !philo->philo_is_full)
				is_thinking(philo->id);
		}
	}
	else
	{
		while (*(philo)->is_died == 0)
		{
			if(*philo->is_died == 0)
				is_eating(philo);
			if(*philo->is_died == 0)
				is_sleeping(philo->time_to_sleep, philo->id);
			if(*philo->is_died == 0 )
				is_thinking(philo->id);
		}
	}
	printf("%d eat %d\n", philo->id, philo->times_eat);
	return NULL;
}
