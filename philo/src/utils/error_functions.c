/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:37:18 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/14 19:54:30 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

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

int	check_args(int argc, char **argv)
{
	long int	num;

	num = 0;
	if(argc == 5 || argc == 6)
	{
		while (--argc != 0)
		{
			if (ft_check_arg(argv[argc]))
				return (0);
			num = ft_atoi_check(argv[argc]);
			if (num > 2147483647)
				return (0);
		}
	}
	if(ft_atoi_check(argv[1]) > 200)
		return (0);
	return(1);
}

