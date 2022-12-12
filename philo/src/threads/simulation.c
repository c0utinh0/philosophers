/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:26 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 18:53:59 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void *thread_simulation(void *temp)
{
	t_philo *philo = (t_philo *)temp;

	if (philo->times_must_eat > 0)
	{
		while (*(philo)->died == 0 && philo->times_must_eat > philo->times_eat)
		{	
			if(*philo->died == 0)
				is_eating(philo);
			if(*philo->died == 0)
				is_sleeping(philo->time_to_sleep, philo->id);
			if(*philo->died == 0)
				is_thinking(philo->id);
		}
	}
	else
	{
		while (*(philo)->died == 0)
		{
			if(*philo->died == 0)
				is_eating(philo);
			if(*philo->died == 0)
				is_sleeping(philo->time_to_sleep, philo->id);
			if(*philo->died == 0)
				is_thinking(philo->id);
		}
	}
	printf("%d eat %d\n", philo->id, philo->times_eat);
	return NULL;
}
