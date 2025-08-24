/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:46:27 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/24 16:06:37 by aaugusto         ###   ########.fr       */
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

// Structs
typedef	struct s_table
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	pthread_mutex_t	mutex;
	bool			end;
	pthread_mutex_t	print;
}				t_table;

typedef	struct s_philosophers
{
	int				id_number;
	int				meal_number;
	pthread_mutex_t	*left_silverware;
	pthread_mutex_t	*right_silverware;
	suseconds_t		start;
	suseconds_t		last_meal;
	pthread_t		thread_id;
	t_table			*table;
}				t_philosophers;


// Parser
int				parser(int argc,char **argv);
int				number_verificator(int argc);

// Init
void			init_table(t_table	*table, char **argv);
pthread_mutex_t	*init_silverware(t_table *table);
t_philosophers	*init_philos(t_table *table, pthread_mutex_t *silverware);

// Loop
void	*loop(void	*table);

// Checker
void	checker(t_philosophers *philo, t_table *table);

// Utils
bool			is_digit(char c);
int				ft_atoi(char *str);
suseconds_t		get_time(void);
void			ft_usleep(long long ms);
void			print_status(t_philosophers *philo, char *msg);

// Routine
void			think(t_philosophers *philo);
void			take_silverware(t_philosophers *philo);
void			eat(t_philosophers *philo);
void			drop_silverware(t_philosophers *philo);
void			sleep_philo(t_philosophers *philo);

// Start
void			start(t_table *table, pthread_mutex_t *silverware, t_philosophers *philo);

// Frees
void			free_silverware(pthread_mutex_t *silverware, int end);
#endif