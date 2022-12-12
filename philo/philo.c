/* ************************************************************************** */
/*                                                   utils                         */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 14:16:20 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_simulation *simulation;

	printf("chech 01\n");
	simulation = malloc(sizeof(t_simulation));
	printf("chech 02\n");
	create_philos(argv, argc, &simulation);
	printf("chech 03\n");
	threads(&simulation);
	printf("chech end\n");

	return (0);
}
