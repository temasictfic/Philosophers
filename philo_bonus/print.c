/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:28:03 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 21:54:44 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(t_philo *philo, char *msg)
{
	if (msg != NULL && philo->table->is_printing != NULL)
	{
		sem_wait(philo->table->is_printing);
		if (!philo->table->stop)
			printf("%zu %zu %s\n", time_ms_from_start(philo->table), philo->id,
				msg);
		sem_post(philo->table->is_printing);
	}
}

int	err_msg(char *msg, char *arg)
{
	printf("philo: %s: %s\n", msg, arg);
	return (0);
}
