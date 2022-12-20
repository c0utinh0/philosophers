/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:57:17 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/19 13:55:29 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void is_sleeping(t_philo *philo)
{
	printf(" %lldms %d %s\n", interval_timestamp(philo->is_born), philo->id, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
}
