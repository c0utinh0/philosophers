/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:55:03 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/19 13:58:45 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void is_thinking(t_philo *philo)
{
	printf(" %lldms %d %s\n", interval_timestamp(philo->is_born), philo->id, "is thinking");
}
