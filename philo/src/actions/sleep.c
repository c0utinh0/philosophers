/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:57:17 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 15:53:36 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void is_sleeping(int time, int philo)
{
		printf("%lld %d is sleeping\n", current_timestamp(), philo);
		usleep(time * 1000);
}
