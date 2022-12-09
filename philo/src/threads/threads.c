/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/09 17:55:12 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void threads(t_philo **philos)
{
	t_philo *philo;

	philo = *philos;
	while (philo != NULL)
	{
		pthread_create(&philo->t_id, NULL, simulation, (void *)philo);
		philo = philo->right;
	}
	philo = *philos;
	pthread_create(&philo->t_monitor, NULL, monitor, (void *)philo);
	while (philo != NULL)
	{
		pthread_join(philo->t_id, NULL);
		philo = philo->right;
	}
	pthread_join(philo->t_id, NULL);
}
