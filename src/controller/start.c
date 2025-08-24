/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:25:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/24 16:13:55 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	start(t_table *table, pthread_mutex_t *silverware, t_philosophers *philo)
{
	int	i;
	(void)silverware;

	i = -1;
	while (++i < table->number_of_philos)
	{
		philo[i].start = get_time();
		philo[i].last_meal = philo[i].start;
		if (pthread_create(&philo[i].thread_id, NULL, loop, (void *)&philo[i]) != 0)
				write(1,"teste\n", 6); // Fazer erro
	}
	checker(philo, table);
	i = -1;
	while (++i < table->number_of_philos)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			write (1, "teste2\n", 7);
	}
}