/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:27:48 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 21:59:20 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_init(t_philo *philo, t_table *table, int index)
{
	philo->id = index + 1;
	philo->table = table;
	philo->sleeping = 0;
	philo->eating = 0;
	philo->last_eat = time_ms_now();
	philo->num_eat = 0;
}

void	threads_start(t_table *table)
{
	size_t	i;

	sem_unlink("forks");
	sem_unlink("printing");
	sem_unlink("dying");
	table->is_printing = sem_open("printing", O_CREAT, 0666, 1);
	table->is_dying = sem_open("dying", O_CREAT, 0666, 1);
	table->forks = sem_open("forks", O_CREAT, 0666, table->count);
	i = -1;
	while (++i < table->count)
		philo_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->count)
	{
		pthread_create(table->philos[i].thread, NULL, \
				philo_routine, table->philos + i);
	}
	philo_check_stop(table);
}
