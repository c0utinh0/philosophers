/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:11:21 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/06 16:29:49 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long current_timestamp(void)
{
	struct timeval time;
	long long milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return(milliseconds);
}
