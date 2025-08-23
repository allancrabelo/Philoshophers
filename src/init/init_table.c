/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:12:13 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 16:15:11 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	init_table(t_table	*table, char **argv)
{
	table->number_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]) * 1000;
	table->time_to_sleep = ft_atoi(argv[4]) * 1000;
	table->eat_times = -1;
	table->end = false;
	if (argv[5])
		table->eat_times = ft_atoi(argv[5]);
	if (pthread_mutex_init(&table->mutex, NULL) != 0)
		mutex_errors(ERR_MUTEX_INIT_TABLE);
}