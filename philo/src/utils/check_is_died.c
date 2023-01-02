/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:17:48 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/02 16:30:19 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_is_died(t_philo *philo)
{
	pthread_mutex_lock(&(*philo->m_died));
	if (*philo->is_died == 0)
	{
		pthread_mutex_unlock(&(*philo->m_died));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(*philo->m_died));
		return (0);
	}
}

