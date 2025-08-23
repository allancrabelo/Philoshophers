/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:46:27 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 17:32:45 by aaugusto         ###   ########.fr       */
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
}				t_table;

typedef	struct s_philosophers
{
	int				id_number;
	int				meal_number;
	pthread_mutex_t	*left_silverware;
	pthread_mutex_t	*right_silverware;
	suseconds_t		last_meal;
	t_table			*table;
}				t_philosophers;


// Parser
int				parser(int argc,char **argv);
int				number_verificator(int argc);

// Init
void			init_table(t_table	*table, char **argv);
pthread_mutex_t	*init_silverware(t_table *table);
t_philosophers	*init_philos(t_table *table, pthread_mutex_t *silverware);

// Utils
bool			is_digit(char c);
int				ft_atoi(char *str);
suseconds_t		get_time(void);
// Frees
void	free_silverware(pthread_mutex_t *silverware, int end);
#endif