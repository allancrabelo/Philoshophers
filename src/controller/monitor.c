/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:00 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/08 15:00:51 by aaugusto         ###   ########.fr       */
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
	int		dead;
	long	cur;
	long	last_meal;
	long	timestamp;

	dead = 0;
	cur = get_time();
	pthread_mutex_lock(&philo->table->state_mutex);
	last_meal = philo->last_meal;
	if (cur - last_meal > philo->table->time_to_die)
	{
		philo->table->simulation_ended = 1;
		timestamp = cur - philo->table->start_time;
		pthread_mutex_unlock(&philo->table->state_mutex);
		print_death(philo, timestamp);
		dead = 1;
		return (dead);
	}
	pthread_mutex_unlock(&philo->table->state_mutex);
	return (dead);
}

/**
 * @brief Checks if all philosophers have eaten enough meals.
 * 
 * @details Iterates through all philosophers counting how many have reached
 * the required number of meals. If any philosopher died, returns immediately.
 * Uses mutex protection when reading meal counts.
 * 
 * @param table Pointer to the table structure with simulation parameters
 * @param philo Array of philosopher structures
 * @param count Pointer to store the number of philosophers who finished eating
 * @return 1 if a philosopher died, 0 otherwise
 */
static int	check_meals(t_table *table, t_philo *philo, int *count)
{
	int	i;

	i = 0;
	*count = 0;
	while (i < table->number_of_philosophers && !getter_thread_safe(table))
	{
		if (dead(&philo[i]))
			return (1);
		if (table->number_of_meals > 0)
		{
			pthread_mutex_lock(&table->state_mutex);
			if (philo[i].number_of_meals == table->number_of_meals)
				(*count)++;
			pthread_mutex_unlock(&table->state_mutex);
		}
		i++;
	}
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
	int	count;

	while (!getter_thread_safe(table))
	{
		if (check_meals(table, philo, &count))
			return ;
		if (table->number_of_meals > 0 \
&& count == table->number_of_philosophers)
		{
			pthread_mutex_lock(&table->state_mutex);
			table->simulation_ended = 1;
			pthread_mutex_unlock(&table->state_mutex);
			return ;
		}
		usleep(1000);
	}
}
