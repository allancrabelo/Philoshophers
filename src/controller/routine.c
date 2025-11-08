/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:20:08 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/19 17:49:17 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Handles the eating process for a philosopher.
 * 
 * @details Acquires silverware, updates meal tracking, simulates eating time,
 * and releases silverware. Uses mutex protection for shared state updates.
 * 
 * @param philo Pointer to the philosopher structure
 * @return * void 
 */
void	eat(t_philo *philo)
{
	take_silverware(philo);
	pthread_mutex_lock(&philo->table->state_mutex);
	philo->last_meal = get_time();
	if (philo->table->number_of_meals > 0)
		philo->number_of_meals++;
	pthread_mutex_unlock(&philo->table->state_mutex);
	output(philo, EAT);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_silverware);
	pthread_mutex_unlock(philo->right_silverware);
}

/**
 * @brief Controls the order in which philosophers take silverware.
 * 
 * @details If philosopher ID is even, takes left fork first then right
 * silverware.
 * If philosopher ID is odd, takes right fork first then left silverware.
 * This strategy prevents deadlocks by breaking circular wait conditions.
 * 
 * @param philo Pointer to the philosopher structure
 * @return * void 
 */
void	take_silverware(t_philo *philo)
{
	if (philo->id_philo % 2 == 0)
	{
		pthread_mutex_lock(philo->right_silverware);
		output(philo, FORK);
		pthread_mutex_lock(philo->left_silverware);
		output(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_silverware);
		output(philo, FORK);
		pthread_mutex_lock(philo->right_silverware);
		output(philo, FORK);
	}
}
