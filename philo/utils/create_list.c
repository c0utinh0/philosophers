/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:47:35 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/02 16:11:26 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void add_philo_list(t_philo **list, int id)
{
    t_philo *new = malloc(sizeof(t_philo));
 
    if(new)
    {
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


void    create_philo_list(t_core  **core)
{
    int count_philo;
    t_philo *list;

    list = NULL;
    count_philo = (*core)->number_of_philosophers;
    while(count_philo)
        add_philo_list(&list, count_philo--);
    (*core)->philo_list = list;
}
