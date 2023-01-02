/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:47:35 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/01/02 14:37:56 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	init_philo_struct(t_philo *new, int id, t_simulation *simulation)
{
	new->times_eat = 0;
	new->id = id;
	new->last_eat = current_timestamp();
	new->is_died = &(simulation)->is_died;
	new->is_full = &(simulation)->is_full;
	new->is_born = current_timestamp();
	new->philo_is_full = 0;
	pthread_mutex_init(&new->m_fork, NULL);
	pthread_mutex_init(&new->m_full, NULL);
}

static void	add_philo_list(t_philo **list, int id, t_simulation *simulation)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (new)
	{
		init_philo_struct(new, id, simulation);
		if ((*simulation).s_argc == 5 || (*simulation).s_argc == 6)
		{
			new->nop = ft_atoi_check((*simulation).s_argv[1]);
			new->time_to_die = ft_atoi_check((*simulation).s_argv[2]);
			new->time_to_eat = ft_atoi_check((*simulation).s_argv[3]);
			new->time_to_sleep = ft_atoi_check((*simulation).s_argv[4]);
			if ((*simulation).s_argc == 6)
				new->times_must_eat = ft_atoi_check((*simulation).s_argv[5]);
			else
				new->times_must_eat = 0;
		}
		new->right = *list;
		new->left = NULL;
		if (*list)
			(*list)->left = new;
		*list = new;
	}
	else
		printf("Memory Allocation Error!\n");
}

static void	create_first(t_philo **philos)
{
	t_philo	*philo;

	philo = *philos;
	while (philo != NULL)
	{
		if (philo->right == NULL)
			philo->first = *philos;
		philo = philo->right;
	}
}

void	create_philos(char **argv, int argc, t_simulation **simulation,
		t_philo **philo)
{
	int		count_philo;
	t_philo	*philos;

	philos = *philo;
	(*simulation)->s_argc = argc;
	(*simulation)->s_argv = argv;
	count_philo = ft_atoi_check(argv[1]);
	(*simulation)->philos_free = philos;
	(*simulation)->is_died = 0;
	(*simulation)->is_full = 0;
	while (count_philo)
		add_philo_list(philo, count_philo--, *simulation);
	philos = *philo;
	create_first(&philos);
	(*simulation)->philos = &philos;
}
