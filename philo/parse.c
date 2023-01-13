/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:27:56 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 21:44:52 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	unsigned_atoi(char *str)
{
	unsigned long long int	num;
	int						i;

	i = 0;
	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (num > 2147483647)
		return (-1);
	return (num);
}

int	is_valid_input(int ac, char **av)
{
	int	i;
	int	num;

	if (ac < 4 + 1 || ac > 5 + 1)
		return (err_msg(WRONG_ARG_NUM, USAGE));
	i = 1;
	while (i < ac)
	{
		if (!is_all_digit(av[i]))
			return (err_msg(NOT_DIGIT, av[i]));
		num = unsigned_atoi(av[i]);
		if (i == 1 && (num <= 0 || num > MAX_PHILOS))
			return (err_msg(WRONG_PHILO_NUM, av[i]));
		else if (i != 1 && num == -1)
			return (err_msg(OUT_OF_RANGE, av[i]));
		i++;
	}
	return (1);
}

t_table	*parse(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!is_valid_input(ac, av) || !table)
		return (NULL);
	table->count = unsigned_atoi(av[1]);
	table->time_to_die = unsigned_atoi(av[2]);
	table->time_to_eat = unsigned_atoi(av[3]);
	table->time_to_sleep = unsigned_atoi(av[4]);
	table->min_to_eat = -1;
	if (ac - 1 == 5)
		table->min_to_eat = unsigned_atoi(av[5]);
	table->stop = 0;
	table->philos = malloc(table->count * sizeof(t_philo));
	table->forks = malloc(table->count * sizeof(pthread_mutex_t));
	table->time = time_ms_now();
	return (table);
}
