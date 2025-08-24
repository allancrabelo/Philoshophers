/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:39:21 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/24 16:19:36 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"
#include <limits.h>

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (value_errors_arguments(ERR_OUT_OF_LIMITS, 0), 0);
		i++;
	}
	return (sign * result);
}

suseconds_t	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(500);
}

void	print_status(t_philosophers *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->print);
	if (!philo->table->end)
		printf ("%ld %d %s\n", get_time() - philo->start, philo->id_number + 1, msg);
	pthread_mutex_unlock(&philo->table->print);
}