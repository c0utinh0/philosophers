/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:34:04 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/19 13:48:33 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void print_action(char *msg, long time, t_philo *philo)
{
	(void)time;
	printf(" %lldms %d %s\n", interval_timestamp(philo->is_born), philo->id, msg);
}
