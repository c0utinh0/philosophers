/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:16 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 19:37:47 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*thread_monitor(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	while (philo != NULL && *(philo)->is_died == 0)
	{
		if (*(philo)->is_full == philo->nop)
			*(philo)->is_died = 1;
		else if ((current_timestamp() - philo->last_eat) > philo->time_to_die)
		{
			*(philo)->is_died = 1;
			printf(" %lldms %d %s\n", interval_timestamp(philo->is_born),
				philo->id, "is died");
		}
		if (philo->right == NULL && *(philo)->is_died == 0)
			philo = philo->first;
		else if (philo->right != NULL && *(philo)->is_died == 0)
			philo = philo->right;
	}
	return (NULL);
}
