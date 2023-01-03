/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:16 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/02 21:11:56 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*thread_monitor(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	while (philo != NULL)
	{
		pthread_mutex_lock(&(*philo->m_died));
		if (*(philo)->is_full == philo->nop)
		{
			*(philo)->is_died = 1;
			break ;
		}
		else if ((current_timestamp() - philo->last_eat) > philo->time_to_die)
		{
			*(philo)->is_died = 1;
			printf(" %lldms %d %s\n", interval_timestamp(philo->is_born),
				philo->id, "is died");
			break ;
		}
		pthread_mutex_unlock(&(*philo->m_died));
		if (philo->right == NULL && check_is_died(philo))
			philo = philo->first;
		else if (philo->right != NULL && check_is_died(philo))
			philo = philo->right;
	}
	return (NULL);
}
