/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/10 10:13:47 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void threads(t_simulation **simulation)
{
	t_philo *philo;

	philo = *(*simulation)->philos;
	while (philo != NULL)
	{
		pthread_create(&philo->t_id, NULL, thread_simulation, (void *)philo);
		philo = philo->right;
	}
	philo = *(*simulation)->philos;
	// pthread_create(&philo->t_monitor, NULL, monitor, (void *)philo);
	while (philo != NULL)
	{
		pthread_join(philo->t_id, NULL);
		philo = philo->right;
	}
	pthread_join(philo->t_id, NULL);
}
