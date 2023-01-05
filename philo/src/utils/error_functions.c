/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:37:18 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/05 19:53:46 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	check_limits(char *num)
{
	if (ft_atoi_check(num) > 200)
		return (1);
	if (ft_atoi_check(num) <= 0)
		return (1);
	return (0);
}

static int	check_arg(char	*arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
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
	long	num;

	num = 0;
	if (argc == 5 || argc == 6)
	{
		if (check_limits(argv[1]))
			return (0);
		while (--argc != 0)
		{
			if (check_arg(argv[argc]))
				return (0);
			num = ft_atoi_check(argv[argc]);
			if (num <= 0 || num > 2147483647)
				return (0);
		}
		return(1);
	}
	else
		return (0);
}
