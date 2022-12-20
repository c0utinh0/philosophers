/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:44:53 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 09:12:03 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static long int	ft_conversion(char *nptr, int i, long int j)
{
	char	temp;

	temp = *nptr;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		nptr++;
		i--;
	}
	while (('0' <= *nptr) && (*nptr <= '9'))
	{
		j = 10 * j + (*nptr++ - '0');
	}
	if (temp == '-')
		return (j * (-1));
	return (j);
}

long int	ft_atoi_check(const char *nptr)
{
	size_t		i;
	long int	j;

	i = ft_strlen((const char *)nptr);
	j = 0;
	while ((9 <= *nptr && *nptr <= 15) || (*nptr == ' '))
	{
		nptr++;
		--i;
	}
	return (ft_conversion((char *)nptr, i, j));
}
