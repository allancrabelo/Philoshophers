/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:15:02 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/11 18:30:45 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	table_initializer(char **argv, t_table *table)
{
	table->number_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->number_of_meals = -1;
	table->start_time = get_time();
	table->simulation_ended = 0;
	table->silverware = NULL;
	if (argv[5])
		table->number_of_meals = ft_atoi(argv[5]);
	if (pthread_mutex_init(&table->output, NULL) != 0)
		return (error_messages_init(ERR_MUTEX_INIT_TABLE), EXIT_FAILURE);
	if (pthread_mutex_init(&table->state_mutex, NULL) != 0)
		return (error_messages_init(ERR_MUTEX_INIT_TABLE), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	silverware_initializer(t_table *table)
{
	int	i;

	table->silverware = malloc(table->number_of_philosophers * sizeof(pthread_mutex_t));
	if (!table->silverware)
		return(error_messages_malloc(ERR_MALLOC_SILVERWARE), EXIT_FAILURE);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->silverware[i], NULL) != 0)
		{
			free_silverware(table, i);
			return (error_messages_init(ERR_MUTEX_INIT_SILVERWARE), EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	philosophers_initializer(t_table *table, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = malloc (table->number_of_philosophers * sizeof(t_philo));
	if (!*philo)
		return(error_messages_malloc(ERR_MALLOC_PHILOSOPHERS), EXIT_FAILURE);
	while (i < table->number_of_philosophers)
	{
		(*philo)[i].ID_philo = i + 1;
		(*philo)[i].number_of_meals = 0;
		(*philo)[i].last_meal = table->start_time;
		(*philo)[i].left_silverware = &table->silverware[i];
		(*philo)[i].right_silverware = &table->silverware[(i + 1) % table->number_of_philosophers];
		(*philo)[i].table = table;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	initializer(char **argv, t_table *table, t_philo **philo)
{
	if (table_initializer(argv, table))
		return (EXIT_FAILURE);
	if (silverware_initializer(table))
		return (EXIT_FAILURE);
	if (philosophers_initializer(table, philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}