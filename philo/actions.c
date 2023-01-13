/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:27:30 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 23:01:03 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_use_forks(t_philo *philo, int (*mutex_fn)(), char *msg)
{
	mutex_fn(philo->lfork);
	print(philo, msg);
	mutex_fn(philo->rfork);
	print(philo, msg);
}

void	philo_eat(t_philo *philo)
{
	philo_use_forks(philo, pthread_mutex_lock, HAS_TAKEN_FORK);
	print(philo, IS_EATING);
	time_usleep(philo->table->time_to_eat);
	philo->eating = 1;
	philo->last_eat = time_ms_now();
	philo->eating = 0;
	philo->num_eat++;
	philo_use_forks(philo, pthread_mutex_unlock, NULL);
}

void	philo_sleep(t_philo *philo)
{
	philo->sleeping = 1;
	print(philo, IS_SLEEPING);
	time_usleep(philo->table->time_to_sleep);
	philo->sleeping = 0;
}

void	philo_think(t_philo *philo)
{
	print(philo, IS_THINKING);
}

void	*philo_routine(void *philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
	if (philo->id % 2 == 0)
		time_usleep(10);
	while (!philo->table->stop)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
