/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 23:21:51 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/17 08:41:30 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Handles the special case of a single philosopher.
 * 
 * @details With only one fork available, the philosopher takes it but cannot
 * eat (needs 2 forks). Waits for time_to_die and then prints death message.
 * This is a special case that must be handled separately.
 * 
 * @param table Pointer to the table structure
 * @param philo Pointer to the single philosopher structure
 * @return EXIT_FAILURE to indicate the philosopher died
 */
static int	handle_one_philo(t_table *table, t_philo *philo)
{
	long	timestamp;

	output(philo, FORK);
	usleep(table->time_to_die * 1000);
	timestamp = get_time() - table->start_time;
	pthread_mutex_lock(&table->output);
	ft_putnbr_fd(timestamp, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(philo->id_philo, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(DEAD, 1);
	pthread_mutex_unlock(&table->output);
	return (EXIT_FAILURE);
}

/**
 * @brief Creates all philosopher threads.
 * 
 * @details Iterates through all philosophers and creates a thread for each one.
 * Each thread executes the loop() function. If any thread creation fails,
 * returns an error immediately.
 * 
 * @param table Pointer to the table structure
 * @param philo Array of philosopher structures
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
static int	create_threads(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, loop, &philo[i]) != 0)
			return (ft_putstr_fd("Thread error\n", 2), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Waits for all philosopher threads to finish execution.
 * 
 * @details Joins all threads, blocking until they complete. This ensures
 * proper cleanup before the program exits. If any join fails, returns error.
 * 
 * @param table Pointer to the table structure
 * @param philo Array of philosopher structures
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
static int	join_threads(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (ft_putstr_fd("Thread error\n", 2), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Main orchestrator that starts the simulation.
 * 
 * @details Handles special case of 1 philosopher, creates all threads,
 * runs the monitor, and joins all threads when simulation ends.
 * 
 * @param table Pointer to the table structure with simulation parameters
 * @param philo Array of philosopher structures
 * @return EXIT_SUCCESS if simulation completed, EXIT_FAILURE on error
 */
int	start(t_table *table, t_philo *philo)
{
	if (table->number_of_philosophers == 1)
		return (handle_one_philo(table, philo));
	if (create_threads(table, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	monitor(table, philo);
	return (join_threads(table, philo));
}
