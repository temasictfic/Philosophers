/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:27:30 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 21:15:21 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_use_forks(t_philo *philo, int (*sem_fn)(), char *msg)
{
	sem_fn(philo->table->forks);
	print(philo, msg);
	sem_fn(philo->table->forks);
	print(philo, msg);
}

void	philo_eat(t_philo *philo)
{
	philo_use_forks(philo, sem_wait, HAS_TAKEN_FORK);
	print(philo, IS_EATING);
	philo->eating = 1;
	time_usleep(philo->table->time_to_eat);
	philo->last_eat = time_ms_now();
	philo->eating = 0;
	philo->num_eat++;
	philo_use_forks(philo, sem_post, NULL);
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
