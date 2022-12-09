/* ************************************************************************** */
/*                                                   utils                         */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/09 17:57:54 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_philo	*philos;
	//t_simulation *simulation;

	philos = NULL;
	philos = malloc(sizeof(t_philo));
	//simulation = malloc(sizeof(t_simulation));
	//simulation->died = 0;
	//create_philos(&philos, argv, argc, simulation);
	create_philos(&philos, argv, argc);
	threads(&philos);
	return (0);
}
