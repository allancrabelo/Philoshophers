/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:46:27 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/08 15:19:09 by aaugusto         ###   ########.fr       */
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
# include <limits.h>

//Macros
# define DEAD  "\033[0;31mdied\033[0m\n" 
# define FORK "has taken a fork\n"
# define EAT  "is eating\n" 
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"

// Structs 
typedef struct s_table
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_of_meals;
	long			start_time;
	int				simulation_ended;
	pthread_mutex_t	*silverware;
	pthread_mutex_t	output;
	pthread_mutex_t	state_mutex;
}				t_table;

typedef struct s_philo
{
	int				id_philo;
	int				number_of_meals;
	long			last_meal;
	pthread_mutex_t	*left_silverware;
	pthread_mutex_t	*right_silverware;
	pthread_t		thread;
	t_table			*table;
}				t_philo;

// Parser
int		parser(int argc, char **argv);
int		number_verificator(int argc);

// Initializer
int		initializer(char **argv, t_table *table, t_philo **philo);

// Start
int		start(t_table *table, t_philo *philo);

//Utilitaries
void	free_silverware(t_table *table, int count);
int		getter_thread_safe(t_table *table);

// Loop
void	*loop(void *_philo);

// Monitor
void	monitor(t_table *table, t_philo *philo);

// Utils
bool	is_digit(char c);
long	ft_atoi(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(long n, int fd);
long	get_time(void);
void	output(t_philo *philo, char *code);

// Routine
void	eat(t_philo *philo);
void	take_silverware(t_philo *philo);

// Start
int		start(t_table *table, t_philo *philo);
// Frees

#endif