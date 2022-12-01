/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/01 16:27:26 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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

// procedimento para inserir no início
void add_philo_list(t_philo **list, int id)
{
    t_philo *new = malloc(sizeof(t_philo));

    if(new){
        new->id = id;
        new->right = *list;
        new->left = NULL;
        if(*list)
            (*list)->left = new;
        *list = new;
    }
    else
        printf("Memory Allocation Error!\n");
}

// procedimento para inserir no fim
/*
void add_philo_list(t_philo **list, int num)
{
    t_philo *aux, *new = malloc(sizeof(t_philo));

    if(new){
        new->id = num;
        new->right = NULL;

        if(*list == NULL){
            *list = new;
            new->left = NULL;
        }
        else{
            aux = *list;
            while(aux->right)
                aux = aux->right;
            aux->right = new;
            new->left = aux;
        }
    }
    else
        printf("Memory Allocation Error!\n");
}
*/
void	create_list(t_core	**core)
{
	int count_philo;
	t_philo *list;

	list = NULL;
	count_philo = (*core)->number_of_philosophers;
	while(count_philo)
		add_philo_list(&list, count_philo--);
	(*core)->philo_list = list;

	printf("Philosophers: %d\n", (*core)->number_of_philosophers);
	printf("Tempo de Morte: %d\n", (*core)->time_to_die);
	printf("Tempo de Comer: %d\n", (*core)->time_to_eat);
	printf("Tempo de Dormir %d\n", (*core)->time_to_sleep);
	printf("Deve Comer: %d\n", (*core)->number_of_times_each_philosopher_must_eat);
}


int	main(int argc, char *argv[])
{
	t_core	*core;

	printf("%d\n", argc);
	core = NULL;
	core = malloc(sizeof(t_core));
	check_args(argc, argv, core);
	create_list(&core);

	return(0);
}
