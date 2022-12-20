/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:47:35 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/20 11:51:12 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void add_philo_list(t_philo **list, int id, char **argv, int argc, t_simulation *simulation)
{
    t_philo *new = malloc(sizeof(t_philo));

    if (new)
    {
        new->id = id;
        new->times_eat = 0;
        new->last_eat = current_timestamp();
        new->is_died = &(simulation)->is_died;
        new->is_full = &(simulation)->is_full;
        new->is_born = current_timestamp();
        new->philo_is_full = 0;
        pthread_mutex_init(&new->m_fork, NULL);
        pthread_mutex_init(&new->m_full, NULL);
        if (argc == 5 || argc == 6)
        {
            new->number_of_philosophers = ft_atoi_check(argv[1]);
            new->time_to_die = ft_atoi_check(argv[2]);
            new->time_to_eat = ft_atoi_check(argv[3]);
            new->time_to_sleep = ft_atoi_check(argv[4]);
            if (argc == 6)
                new->times_must_eat = ft_atoi_check(argv[5]);
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

static void create_first(t_philo **philos)
{
    t_philo *philo;

    philo = *philos;
    while (philo != NULL) // tratar
    {
        if (philo->right == NULL)
            philo->first = *philos;
        philo = philo->right;
    }
}

void create_philos(char **argv, int argc, t_simulation **simulation)
{
    int count_philo;
    t_philo *philo;
    t_philo *philos;

    philo = NULL;
    philos = NULL;
    count_philo = ft_atoi_check(argv[1]);
    philos = malloc(sizeof(t_philo));
	(*simulation)->philos_free = philos;
    (*simulation)->is_died = 0;
    (*simulation)->is_full = 0;
    while (count_philo)
        add_philo_list(&philo, count_philo--, argv, argc, *simulation);
    philos = philo;
    create_first(&philos);
    (*simulation)->philos = &philos;
}
