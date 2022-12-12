/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:16 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 18:15:16 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void *thread_monitor(void *temp)
{
    t_philo *philo = (t_philo *)temp;

    while (philo != NULL && *(philo)->died == 0)
    {
        if ((current_timestamp() - philo->last_eat) > philo->time_to_die)
        {
            *(philo)->died = 1;
			printf("%lld %d is died\n", current_timestamp(), philo->id);
        }
        if (philo->right == NULL && *(philo)->died == 0)
            philo = philo->first;
        else if (philo->right != NULL && *(philo)->died == 0)
            philo = philo->right;
    }
    return NULL;
}
