/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:51:19 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/21 12:03:15 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Checks if the philosopher should stop executing.
 * 
 * @details Verifies if the simulation has ended or if the philosopher
 * has eaten enough meals. Uses mutex protection to safely read shared state.
 * 
 * @param philo Pointer to the philosopher structure
 * @return 1 if philosopher should stop, 0 if should continue
 */
static int	should_continue(t_philo *philo)
{
	int	ended;

	pthread_mutex_lock(&philo->table->state_mutex);
	ended = philo->table->simulation_ended;
	pthread_mutex_unlock(&philo->table->state_mutex);
	return (ended);
}

/**
 * @brief Main execution loop for each philosopher thread.
 * 
 * @details Implements the philosopher's lifecycle: eat, sleep, think.
 * Even-numbered philosophers start with a small delay to prevent deadlock.
 * Checks if should continue after each action to avoid printing after death.
 * 
 * @param _philo Void pointer to the philosopher structure (cast internally)
 * @return NULL when the philosopher finishes execution
 */
void	*loop(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (!(philo->id_philo % 2))
		usleep(1000);
	while (!should_continue(philo))
	{
		eat(philo);
		if (should_continue(philo))
			break ;
		output(philo, SLEEP);
		usleep(philo->table->time_to_sleep * 1000);
		if (should_continue(philo))
			break ;
		output(philo, THINK);
		if (philo->table->number_of_philosophers % 2 && philo->id_philo % 2)
			usleep(1000);
	}
	return (NULL);
}
