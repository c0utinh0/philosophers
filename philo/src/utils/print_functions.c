/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:34:04 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 16:43:52 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_action(char *msg, t_philo *philo)
{
	printf(" %lldms %d %s\n", interval_timestamp(philo->is_born),
		philo->id, msg);
}
