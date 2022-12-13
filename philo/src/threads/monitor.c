/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:16 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/13 15:51:07 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void *thread_monitor(void *temp)
{
    t_philo *philo = (t_philo *)temp;

    while (philo != NULL && *(philo)->is_died == 0)
    {
		if (*(philo)->is_full >= philo->times_must_eat)
		{
			philo->last_eat = current_timestamp();
            *(philo)->is_died = 1;
		}
		if ((current_timestamp() - philo->last_eat) > philo->time_to_die)
        {
            *(philo)->is_died = 1;
			printf("%lld %d is died\n", current_timestamp(), philo->id);
        }
		if (philo->right == NULL && *(philo)->is_died == 0)
            philo = philo->first;
        else if (philo->right != NULL && *(philo)->is_died == 0)
            philo = philo->right;
    }
    return NULL;
}
