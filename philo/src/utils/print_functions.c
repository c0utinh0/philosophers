/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:34:04 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/05 18:45:09 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_action(char *msg, t_philo *philo)
{

	pthread_mutex_lock(&(*philo->m_print));
	printf(" %lldms %d %s\n", interval_timestamp(philo->is_born),
		philo->id, msg);
	pthread_mutex_unlock(&(*philo->m_print));
}
