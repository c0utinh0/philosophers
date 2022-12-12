/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:16 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 15:33:42 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

// void *thread_monitor(void *temp)
// {
//     t_simulation *sim = (t_simulation *)temp;
//     t_philo **list;
//     t_philo *philos;

//     list = sim->philos;
//     philos = *list;
//     while (1)
//     {
//         while (philos != NULL)
//         {
//             if ((current_timestamp() - philos->last_eat) > philos->time_to_die)
//                 sim->died = 1;
//             philos = philos->right;
//         }
//         philos = *list;
//     }
//     return NULL;
// }

void *thread_monitor(void *temp)
{
    t_philo *philo = (t_philo *)temp;

    while (*(philo)->died == 0)
    {
        if ((current_timestamp() - philo->last_eat) > philo->time_to_die)
        {
			printf("%lld\n", current_timestamp() - philo->last_eat);
            *(philo)->died = 1;
        }
    }
    return NULL;
}
