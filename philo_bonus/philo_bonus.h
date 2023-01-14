/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:28:00 by sciftci           #+#    #+#             */
/*   Updated: 2023/01/13 23:07:21 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
//# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILOS 200
# define HAS_TAKEN_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define HAS_DIED "died"

# define NOT_DIGIT "Argument contains character other than positive digit"
# define OUT_OF_RANGE "Argument bigger than INT_MAX"
# define WRONG_PHILO_NUM "Philo number must be bigger than 0 and maximum 200"
# define WRONG_ARG_NUM "Argument number must be 4 or 5"
# define USAGE "\n./philo <num_of_philo> <time_to_die> <time_to_eat> <time_to_sleep> \
[num_of_must_eat]"

typedef struct s_philo
{
	size_t			id;
	pthread_t		thread;

	int				eating;
	size_t			last_eat;
	int				num_eat;
	int				sleeping;

	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	sem_t			*forks;
	t_philo			*philos;
	size_t			count;

	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_to_die;
	int				min_to_eat;
	int				stop;

	size_t			time;
	sem_t			*is_dying;
	sem_t			*is_printing;
}					t_table;

void				print(t_philo *philo, char *msg);
int					err_msg(char *msg, char *arg);

t_table				*parse(int ac, char **av);
void				*philo_routine(void *philo_struct);
void				threads_start(t_table *table);
void				philo_check_stop(t_table *table);

time_t				time_ms_now(void);
time_t				time_ms_from_start(t_table *table);
void				time_usleep(size_t usec);

#endif