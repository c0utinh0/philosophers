/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:28:06 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 14:57:26 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	remove_philos(t_simulation **simulation)
{
	t_philo	*next;
	t_philo	*tmp;

	tmp = *(*simulation)->philos;
	while (tmp != NULL)
	{
		next = tmp->right;
		free(tmp);
		tmp = next;
	}
	free((*simulation)->philos_free);
}

static void	destroy_mutex(t_simulation **simulation)
{
	t_philo	*philo;
	t_philo	*init;

	philo = *(*simulation)->philos;
	init = philo;
	while (philo != NULL)
	{
		pthread_mutex_destroy(&philo->m_fork);
		philo = philo->right;
	}
	philo = init;
	while (philo != NULL)
	{
		pthread_mutex_destroy(&philo->m_full);
		philo = philo->right;
	}
}

void	stop_simulation(t_simulation **simulation)
{
	remove_philos(simulation);
	destroy_mutex(simulation);
}
