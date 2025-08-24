/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:18:04 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/24 16:10:36 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*loop(void	*table)
{
	t_philosophers	*philo;


	philo = (t_philosophers *)table;
	if (philo->id_number % 2 == 0)
		usleep(1000);
	while (!philo->table->end)
	{
		think(philo);
		take_silverware(philo);
		eat(philo);
		drop_silverware(philo);
		sleep_philo(philo);
	}
	return (NULL);
}
