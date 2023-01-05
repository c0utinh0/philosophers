/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:57:17 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/05 18:45:27 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(*philo->m_print));
	printf(" %lldms %d %s\n", interval_timestamp(philo->is_born),
		philo->id, "is sleeping");
	pthread_mutex_unlock(&(*philo->m_print));
	usleep(philo->time_to_sleep * 1000);
}
