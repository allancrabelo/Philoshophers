/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:51:19 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/08 16:52:48 by aaugusto         ###   ########.fr       */
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
 * @brief Checks if philosopher has eaten enough meals.
 * 
 * @details Used to stop the philosopher immediately after eating
 * the required number of meals, preventing unnecessary sleep/think.
 * 
 * @param philo Pointer to the philosopher structure
 * @return 1 if philosopher finished eating required meals, 0 otherwise
 */
static int	finished_eating(t_philo *philo)
{
	int	finished;

	pthread_mutex_lock(&philo->table->state_mutex);
	finished = 0;
	if (philo->table->number_of_meals > 0
		&& philo->number_of_meals >= philo->table->number_of_meals)
		finished = 1;
	pthread_mutex_unlock(&philo->table->state_mutex);
	return (finished);
}

/**
 * @brief Main execution loop for each philosopher thread.
 * 
 * @details Implements the philosopher's lifecycle: eat, sleep, think.
 * Even-numbered philosophers start with a small delay to prevent deadlock.
 * Checks if should continue after each action to avoid printing after death.
 * Now also checks if finished eating to stop immediately after last meal.
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
		if (should_continue(philo) || finished_eating(philo))
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
