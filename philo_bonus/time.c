/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:28:06 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 21:55:02 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

struct timeval	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}

time_t	time_ms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

time_t	time_ms_now(void)
{
	return (time_ms(time_now()));
}

time_t	time_ms_from_start(t_table *table)
{
	return (time_ms_now() - table->time);
}

void	time_usleep(size_t usec)
{
	size_t	current;

	current = time_ms_now();
	while (usec > time_ms_now() - current)
		usleep(usec * 10);
}
