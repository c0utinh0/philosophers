/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/08 19:26:25 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int argc, char *argv[])
{
	t_philo	*philos;

	philos = NULL;
	philos = malloc(sizeof(t_philo));
	create_philos(&philos, argv, argc);
	create_thread(&philos);
	return (0);
}
