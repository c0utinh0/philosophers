/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/08 18:02:07 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
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
*/

int main(int argc, char *argv[])
{
	t_philo	*philos;
//	pthread_mutex_t	m_eating;

	philos = NULL;
	philos = malloc(sizeof(t_philo));
	//	check_args(argc, argv, philos);
	//	create_philos(&philos, argv, argc, &m_eating);
	create_philos(&philos, argv, argc);
	create_thread(&philos);
	return (0);
}
