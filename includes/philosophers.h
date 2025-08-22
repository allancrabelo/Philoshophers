/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:46:27 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 16:50:28 by aaugusto         ###   ########.fr       */
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
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int 	time_to_sleep;
}				t_table;

typedef	struct s_philosophers
{
	int		id_number;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_eaten;
	t_table	*table;
}				t_philosophers;


// Parser
int		parser(int argc,char **argv);
int		number_verificator(int argc);

// Utils
bool	is_digit(char c);
int		ft_atoi(char *str);
#endif