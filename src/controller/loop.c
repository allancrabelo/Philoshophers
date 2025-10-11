/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:51:19 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/11 18:35:00 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*loop(void *_philo)
{
	t_philo *philo;

	philo = (t_philo *)_philo;
	if (!(philo->ID_philo % 2))
		usleep(1000);
	while (!getter_thread_safe(philo->table))
	{
		eat(philo);
		if (getter_thread_safe(philo->table))
			break ;
		output(philo, SLEEP);
		usleep(philo->table->time_to_sleep * 1000);
		if (getter_thread_safe(philo->table))
			break ;
		output(philo, THINK);
		if (philo->table->number_of_philosophers % 2 && philo->ID_philo % 2)
			usleep(1000);
	}
	return (NULL);
}