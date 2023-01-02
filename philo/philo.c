/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:35 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/02 13:37:55 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	*simulation;
	t_philo			**philo;

	if (check_args(argc, argv))
	{
		simulation = malloc(sizeof(t_simulation));
		philo = malloc(sizeof(t_philo));
		if (!simulation || !philo)
			return (1);
		create_philos(argv, argc, &simulation, philo);
		threads(&simulation);
		free(simulation);
		free(philo);
	}
	return (0);
}
