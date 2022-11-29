/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/11/29 14:57:30 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_core	*create_core(void)
{
	return (NULL);
}

void	create_list(t_core	**core)
{
	printf("%d\n", (*core)->number_of_philosophers);
	printf("%d\n", (*core)->time_to_die);
	printf("%d\n", (*core)->time_to_eat);
	printf("%d\n", (*core)->time_to_sleep);
	printf("%d\n", (*core)->number_of_times_each_philosopher_must_eat);
}

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
	}
}

int	main(int argc, char *argv[])
{
	t_core	*core;

	core = create_core();
	core = (t_core *)malloc(sizeof(t_core));
	check_args(argc, argv, core);
	create_list(&core);

	return(0);
}
