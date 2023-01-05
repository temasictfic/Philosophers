/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:27:44 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/05 04:27:45 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	philo_check_min_eat(t_table *table)
{
	size_t	i;

	if (table->min_to_eat < 0)
		return (0);
	i = -1;
	while (++i < table->count)
	{
		if (table->philos[i].num_eat < table->min_to_eat)
			return (0);
	}
	return (1);
}

void	philo_check_death(t_table *table)
{
	size_t	i;

	if (table->count == 1)
		print(table->philos, HAS_DIED);
	while (table->count > 1)
	{
		i = -1;
		while (++i < table->count)
		{
			pthread_mutex_lock(&table->is_dying);
			if ((time_ms_now()
					- table->philos[i].last_eat) >= table->time_to_die)
			{
				print(table->philos + i, HAS_DIED);
				table->death = 1;
				break ;
			}
			pthread_mutex_unlock(&table->is_dying);
		}
		if (philo_check_min_eat(table) || table->death)
			break ;
	}
}
