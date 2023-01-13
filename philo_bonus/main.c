/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:27:52 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 23:50:05 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	table_free(t_table *table)
{
	time_usleep(100);
	sem_close(table->forks);
	sem_close(table->is_dying);
	sem_close(table->is_printing);
	sem_unlink("forks");
	sem_unlink("dying");
	sem_unlink("printing");
	free(table->philos);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = parse(ac, av);
	if (table != NULL)
	{
		threads_start(table);
		table_free(table);
	}
	return (0);
}
