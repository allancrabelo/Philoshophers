/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:25:06 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/15 00:03:42 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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

static void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n /= 10, fd);
	ft_putchar((n % 10) + '0', fd);
}

void	output(t_philo *philo, char *code)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->state_mutex);
	if (!philo->table->end)
	{
		timestamp = get_time() - philo->table->start_time;
		pthread_mutex_lock(&philo->table->output);
		ft_putnbr_fd(timestamp, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(philo->ID_philo, 1);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(code, 1);
		pthread_mutex_unlock(&philo->table->output);
	}
	pthread_mutex_unlock(&philo->table->state_mutex);
}