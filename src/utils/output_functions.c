/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:25:06 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/08 16:51:29 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Writes a string to a file descriptor.
 * 
 * @details Iterates through the string and writes each character using write().
 * Used for outputting messages to stdout (fd=1) or stderr (fd=2).
 * 
 * @param str String to write
 * @param fd File descriptor (1=stdout, 2=stderr)
 * @return void
 */
void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

/**
 * @brief Writes a single character to a file descriptor.
 * 
 * @details Helper function used by ft_putnbr_fd to output individual digits.
 * 
 * @param c Character to write
 * @param fd File descriptor
 * @return void
 */
static void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
}

/**
 * @brief Writes a long integer to a file descriptor.
 * 
 * @details Recursively converts the number to characters and outputs them.
 * Used for printing timestamps and philosopher IDs.
 * 
 * @param n Number to write
 * @param fd File descriptor
 * @return void
 */
void	ft_putnbr_fd(long n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar((n % 10) + '0', fd);
}

/**
 * @brief Thread-safe output function for philosopher actions.
 * 
 * @details Prints formatted message: "timestamp ID action".
 * Checks if simulation ended before printing to avoid messages after death.
 * Uses mutex protection to prevent garbled output from multiple threads.
 * Calculates timestamp DENTRO do mutex para garantir ordem correta.
 * 
 * @param philo Pointer to the philosopher structure
 * @param code Action string (FORK, EAT, SLEEP, THINK)
 * @return void
 */
void	output(t_philo *philo, char *code)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->output);
	if (!philo->table->simulation_ended)
	{
		timestamp = get_time() - philo->table->start_time;
		ft_putnbr_fd(timestamp, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(philo->id_philo, 1);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(code, 1);
	}
	pthread_mutex_unlock(&philo->table->output);
}
