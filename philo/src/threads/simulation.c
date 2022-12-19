/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:26 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/19 14:02:09 by dcoutinh         ###   ########.fr       */
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
				is_sleeping(philo);
			if(*philo->is_died == 0)
				is_thinking(philo);
		}
	}
	else
	{
		while (*(philo)->is_died == 0)
		{
			if(*philo->is_died == 0)
				is_eating(philo);
			if(*philo->is_died == 0)
				is_sleeping(philo);
			if(*philo->is_died == 0 )
				is_thinking(philo);
		}
	}
	return NULL;
}
