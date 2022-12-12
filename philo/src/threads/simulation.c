/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:26 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 15:18:00 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void *thread_simulation(void *temp)
{
	t_philo *philo = (t_philo *)temp;

	while (*(philo)->died == 0)
	{
		if (philo->right == NULL)
		{
			if (*(philo)->died == 0)
				is_eating(philo);
			if (*(philo)->died == 0)
				is_sleeping(philo->time_to_sleep, philo->id);
			if (*(philo)->died == 0)
				is_thinking(philo->id);
		}
		else
		{
			if (*(philo)->died == 0)
				is_eating(philo);
			if (*(philo)->died == 0)
				is_sleeping(philo->time_to_sleep, philo->id);
			if (*(philo)->died == 0)
				is_thinking(philo->id);
		}
	}
	printf("%lld %d is died\n", current_timestamp(), philo->id);
	return NULL;
}
