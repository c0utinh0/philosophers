/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:47:35 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/08 18:15:26 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//static void add_philo_list(t_philo **list, int id, char **argv, int argc, pthread_mutex_t	m_eating)
static void add_philo_list(t_philo **list, int id, char **argv, int argc)
{
    t_philo *new = malloc(sizeof(t_philo));

    if (new)
    {
        new->id = id;
		//new->eating = &m_eating;
        if (argc == 5 || argc == 6)
        {
            new->number_of_philosophers = ft_atoi(argv[1]); // Tratar MAX 200 Phili
            new->time_to_die = ft_atoi(argv[2]);
            new->time_to_eat = ft_atoi(argv[3]);
            new->time_to_sleep = ft_atoi(argv[4]);
            if (argc == 6)
                new->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
            else
                new->number_of_times_each_philosopher_must_eat = 0;
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

//void	create_philos(t_philo **philos, char **argv, int argc, pthread_mutex_t	*m_eating)
void	create_philos(t_philo **philos, char **argv, int argc)
{
    int count_philo;
    t_philo *philo;

    philo = NULL;
    count_philo = ft_atoi(argv[1]);
//	while (count_philo)
//		add_philo_list(&philo, count_philo--, argv, argc, *m_eating);
    while (count_philo)
        add_philo_list(&philo, count_philo--, argv, argc);
    *philos = philo;
	create_first(philos);
}
