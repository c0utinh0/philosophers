/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:37:18 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/13 17:54:59 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"


long int	num;

	num = 0;
	while (--argc != 0)
	{
		if (ft_check_arg(argv[argc]))
			return (1);
		num = ft_atoi(argv[argc]);
		if (num > 2147483647)
			return (1);
		ft_add_node(p, num);
	}
	return (0);

int	ft_check_arg(char	*arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
		while (arg[i] != '\0')
		{
			if (!(ft_isdigit(arg[i])))
				return (1);
			i++;
		}
	}
	else
	{
		while (arg[i] != '\0')
		{
			if (!(ft_isdigit(arg[i])))
				return (1);
			i++;
		}
	}
	return (0);
}

if(argc == 5 || argc == 6)
	{
		core->number_of_philosophers = ft_atoi(argv[1]); //Tratar MAX 200 Philos
		core->time_to_die = ft_atoi(argv[2]);
		core->time_to_eat = ft_atoi(argv[3]);
		core->time_to_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			core->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}


int	check_args(int argc, char **argv)
{
	if(argc == 5 || argc == 6)
	{
		core->number_of_philosophers = ft_atoi(argv[1]); //Tratar MAX 200 Philos
		core->time_to_die = ft_atoi(argv[2]);
		core->time_to_eat = ft_atoi(argv[3]);
		core->time_to_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			core->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
	return(0);
}

