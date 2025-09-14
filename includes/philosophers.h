/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:46:27 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/15 00:03:12 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// Includes
# include "colors.h"
# include "errors.h"
# include <string.h>		// memset
# include <stdio.h>			// printf
# include <stdlib.h>		// malloc, free
# include <unistd.h>		// write, usleep
# include <sys/time.h>		// gettimeofday
# include <pthread.h>		// mutex
# include <stdbool.h>

//Macros
# define SILVERWARE "is holding silverware\n"

// Structs
typedef struct s_table
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_of_meals;
	long			start_time;
	int				end;
	pthread_mutex_t	*silverware;
	pthread_mutex_t	output;
	pthread_mutex_t	state_mutex;
}				t_table;

typedef struct s_philo
{
	int				ID_philo;
	int				number_of_meals;
	long			last_meal;
	pthread_mutex_t	*left_silverware;
	pthread_mutex_t	*right_silverware;
	pthread_t		thread;
	t_table			*table;
}				t_philo;

// Parser
int		parser(int argc,char **argv);
int		number_verificator(int argc);

// Initializer
int		initializer(char **argv, t_table *table, t_philo **philo);

//Dead
void	free_silverware(t_table *table, int count);

// Loop

// Checker

// Utils
bool	is_digit(char c);
int		ft_atoi(char *str);
void	ft_putstr_fd(char *str, int fd);
long	get_time(void);
void	output(t_philo *philo, char *code);

// Routine

// Start
int		start(t_table *table, t_philo *philo);
// Frees

#endif