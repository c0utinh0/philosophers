/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:35 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 13:57:00 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	*simulation;

	if (check_args(argc, argv))
	{
		simulation = malloc(sizeof(t_simulation));
		if (!simulation)
			return (1);
		create_philos(argv, argc, &simulation);
		threads(&simulation);
		free(simulation);
	}
	return (0);
}
