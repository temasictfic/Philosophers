/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:28:03 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 22:29:32 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *msg)
{
	if (msg != NULL)
	{
		pthread_mutex_lock(&philo->table->is_printing);
		if (!philo->table->stop)
			printf("%zu %zu %s\n", time_ms_from_start(philo->table), philo->id,
				msg);
		pthread_mutex_unlock(&philo->table->is_printing);
	}
}

int	err_msg(char *msg, char *arg)
{
	printf("philo: %s: %s\n", msg, arg);
	return (0);
}
