/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/06 17:28:17 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    *thread_func(void  *temp)
{
	t_philo *philo = (t_philo *) temp;

	printf("%lld X Id: %d\n", current_timestamp(), philo->id);
	return NULL;
}

void    create_thread(t_philo  **philos)
{
	t_philo	*philo;

	philo = *philos;
	while(philo != NULL)
	{
		pthread_create(&philo->t_id, NULL, thread_func, (void *)philo);
		philo = philo->right;
	}
	philo = *philos;
	while(philo != NULL)
	{
		pthread_join(philo->t_id, NULL);
		philo = philo->right;
	}

}
