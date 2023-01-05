/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:27:48 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/05 09:35:57 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int index)
{
	philo->id = index + 1;
	philo->table = table;
	philo->sleeping = 0;
	philo->eating = 0;
	philo->last_eat = time_ms_now();
	philo->num_eat = 0;
	pthread_mutex_init(table->forks + index, NULL);
}

void	philo_init_forks(t_philo *philo, t_table *table, int index)
{
	if (index - 1 < 0)
		philo->lfork = table->forks + (table->count - 1);
	else
		philo->lfork = table->forks + (index - 1);
	philo->rfork = table->forks + index;
}

void	threads_start(t_table *table)
{
	size_t	i;

	pthread_mutex_init(&table->is_printing, NULL);
	pthread_mutex_init(&table->is_dying, NULL);
	i = -1;
	while (++i < table->count)
	{
		philo_init(table->philos + i, table, i);
		philo_init_forks(table->philos + i, table, i);
		pthread_create(&table->philos[i].thread, NULL, philo_routine,
			table->philos + i);
	}
	philo_check_death(table);
}
