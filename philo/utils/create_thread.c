/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/12/06 15:47:24 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    *thread_func(void  *temp)
{
	t_philo *philo = (t_philo *) temp;

	printf("Id: %d\n", philo->id);
	return NULL;
}

void    create_thread(t_core  **core)
{
	t_philo	*temp;

	temp = (*core)->philo_list;
	while(temp != NULL)
	{
		pthread_create(&temp->t_id, NULL, thread_func, (void *)temp);
		temp = temp->right;
	}
	temp = (*core)->philo_list;
	while(temp != NULL)
	{
		pthread_join(temp->t_id, NULL);
		temp = temp->right;
	}

}
