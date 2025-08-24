/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:54:40 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/24 16:03:04 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	think(t_philosophers *philo)
{
	print_status(philo, "is thinking");
}

void	take_silverware(t_philosophers *philo)
{
	pthread_mutex_lock(philo->left_silverware);
	print_status(philo, "has taken a silverware");
	pthread_mutex_lock(philo->right_silverware);
	print_status(philo, "has taken a silverware");
}

void	eat(t_philosophers *philo)
{
	print_status(philo, "is eating");
	philo->last_meal = get_time();
	philo->meal_number++;
	ft_usleep(philo->table->time_to_eat);
}

void	drop_silverware(t_philosophers *philo)
{
	pthread_mutex_unlock(philo->left_silverware);
	pthread_mutex_unlock(philo->right_silverware);
}

void	sleep_philo(t_philosophers *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}