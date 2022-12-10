/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/10 19:42:19 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

// void threads(t_simulation **simulation)
// {
// 	t_philo *philo;
// 	t_simulation *sim;

// 	philo = *(*simulation)->philos;
// 	sim = *simulation;
// 	while (philo != NULL)
// 	{
// 		pthread_create(&philo->t_id, NULL, thread_simulation, (void *)philo);
// 		philo = philo->right;
// 	}
// 	pthread_create(&sim->t_simulation, NULL, thread_monitor, (void *)sim);
// 	philo = *(*simulation)->philos;
// 	while (philo != NULL)
// 	{
// 		pthread_join(philo->t_id, NULL);
// 		philo = philo->right;
// 	}
// 	pthread_join(sim->t_simulation, NULL);
// }

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
	while (philo != NULL)
	{
		pthread_create(&philo->t_monitor, NULL, thread_monitor, (void *)philo);
		philo = philo->right;
	}
	philo = *(*simulation)->philos;
	while (philo != NULL)
	{
		pthread_join(philo->t_id, NULL);
		philo = philo->right;
	}
	philo = *(*simulation)->philos;
	while (philo != NULL)
	{
		pthread_join(philo->t_monitor, NULL);
		philo = philo->right;
	}
}
