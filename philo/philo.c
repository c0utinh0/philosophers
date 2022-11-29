/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:54:34 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/11/29 20:10:36 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_list(t_core	**core)
{
	printf("%d\n", (*core)->number_of_philosophers);
	printf("%d\n", (*core)->time_to_die);
	printf("%d\n", (*core)->time_to_eat);
	printf("%d\n", (*core)->time_to_sleep);
	printf("%d\n", (*core)->number_of_times_each_philosopher_must_eat);
}

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
	}
}
/*
// procedimento para inserir no fim
void inserir_no_fim(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL){
            *lista = novo;
            novo->anterior = NULL;
        }
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}
*/
int	main(int argc, char *argv[])
{
	t_core	*core;

	core = NULL;
	core = malloc(sizeof(t_core));
	create_philo_list(core->philo);
	check_args(argc, argv, core);
	create_list(&core);

	return(0);
}
