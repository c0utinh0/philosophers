/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/06 14:34:47 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	check_args(int argc, char **argv, t_core *core)
{
	//TRATAR INPUTS
	if(argc == 5 || argc == 6)
	{
		core->number_of_philosophers = ft_atoi(argv[1]); //Tratar MAX 200 Philos
		core->time_to_die = ft_atoi(argv[2]);
		core->time_to_eat = ft_atoi(argv[3]);
		core->time_to_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			core->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else 
			core->number_of_times_each_philosopher_must_eat = 0;
	}
}

int	main(int argc, char *argv[])
{
	t_core	*core;

	core = NULL;
	core = malloc(sizeof(t_core));
	check_args(argc, argv, core);
	create_philo_list(&core);
	create_thread(&core);

	printf("============================\n");

	printf("Philosophers: %d\n", (core)->number_of_philosophers);
	printf("Tempo de Morte: %d\n", (core)->time_to_die);
	printf("Tempo de Comer: %d\n", (core)->time_to_eat);
	printf("Tempo de Dormir %d\n", (core)->time_to_sleep);
	printf("Deve Comer: %d\n", (core)->number_of_times_each_philosopher_must_eat);

	return(0);
}
