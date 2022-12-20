/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:28:06 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 11:50:34 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	remove_philos(t_simulation **simulation)
{
	t_philo	*next;
	t_philo	*tmp;

	tmp = *(*simulation)->philos;
	while (tmp != NULL)
	{
		next = tmp->right;
		free(tmp);
		tmp = next;
	}
	free((*simulation)->philos_free);
}
