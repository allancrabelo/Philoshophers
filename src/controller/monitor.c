/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:00 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/08 16:52:24 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Prints the death message for a philosopher.
 * 
 * @details Safely outputs the death message with mutex protection
 * to prevent garbled output. Format: "timestamp ID died"
 * 
 * @param philo Pointer to the philosopher structure
 * @param timestamp The time in ms when the philosopher died
 * @return void
 */
static void	print_death(t_philo *philo, long timestamp)
{
	pthread_mutex_lock(&philo->table->output);
	ft_putnbr_fd(timestamp, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(philo->id_philo, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(DEAD, 1);
	pthread_mutex_unlock(&philo->table->output);
}

/**
 * @brief Checks if a philosopher has died from starvation.
 * 
 * @details Calculates the time since last meal and compares with time_to_die.
 * If dead, marks simulation_ended and prints death message.
 * Uses mutex protection to safely read last_meal timestamp.
 * 
 * @param philo Pointer to the philosopher structure
 * @return 1 if philosopher is dead, 0 if alive
 */
static int	dead(t_philo *philo)
{
	long	cur;
	long	last_meal;
	long	timestamp;

	pthread_mutex_lock(&philo->table->state_mutex);
	cur = get_time();
	last_meal = philo->last_meal;
	if (cur - last_meal > philo->table->time_to_die)
	{
		philo->table->simulation_ended = 1;
		timestamp = cur - philo->table->start_time;
		pthread_mutex_unlock(&philo->table->state_mutex);
		print_death(philo, timestamp);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->state_mutex);
	return (0);
}

/**
 * @brief Checks if all philosophers have eaten enough meals.
 * 
 * @details Iterates through all philosophers counting how many have reached
 * the required number of meals. Only ends simulation when all have eaten
 * AND are not currently eating (to ensure last action printed is eating).
 * Uses mutex protection when reading meal counts.
 * 
 * @param table Pointer to the table structure with simulation parameters
 * @param philo Array of philosopher structures
 * @return 1 if all finished eating, 0 otherwise
 */
static int	check_all_ate(t_table *table, t_philo *philo)
{
	int	i;
	int	count;

	if (table->number_of_meals <= 0)
		return (0);
	i = 0;
	count = 0;
	pthread_mutex_lock(&table->state_mutex);
	while (i < table->number_of_philosophers)
	{
		if (philo[i].number_of_meals >= table->number_of_meals)
			count++;
		i++;
	}
	if (count == table->number_of_philosophers)
	{
		table->simulation_ended = 1;
		pthread_mutex_unlock(&table->state_mutex);
		usleep(1000);
		return (1);
	}
	pthread_mutex_unlock(&table->state_mutex);
	return (0);
}

/**
 * @brief Main monitoring function that supervises all philosophers.
 * 
 * @details Continuously checks if any philosopher died or if all have eaten
 * enough meals. Runs in the main thread while philosopher threads execute.
 * When termination condition is met, marks simulation_ended and returns.
 * 
 * @param table Pointer to the table structure with simulation parameters
 * @param philo Array of all philosopher structures
 * @return void
 */
void	monitor(t_table *table, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			if (dead(&philo[i]))
				return ;
			i++;
		}
		if (check_all_ate(table, philo))
			return ;
		usleep(1000);
	}
}
