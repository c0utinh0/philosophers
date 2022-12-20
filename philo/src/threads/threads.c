/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 16:38:20 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	threads(t_simulation **simulation)
{
	t_philo	*philo;
	t_philo	*init;

	philo = *(*simulation)->philos;
	init = philo;
	while (philo != NULL)
	{
		pthread_create(&philo->t_id, NULL, thread_simulation, (void *)philo);
		philo = philo->right;
	}
	philo = init;
	pthread_create(&philo->t_monitor, NULL, thread_monitor, (void *)philo);
	while (philo != NULL)
	{
		pthread_join(philo->t_id, NULL);
		philo = philo->right;
	}
	philo = init;
	pthread_join(philo->t_monitor, NULL);
	stop_simulation(simulation);
}
