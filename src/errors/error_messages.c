/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:43:39 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/14 18:16:06 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	error_messages_input(int code)
{
	if (code == ERR_INVALID_NUM_ARGS)
	{
		ft_putstr_fd(RED "[ERROR 101] Usage: ./philo " RESET, 2);
		ft_putstr_fd(RED "<number_of_philosophers> <time_to_die> " RESET, 2);
		ft_putstr_fd(RED "<time_to_eat> <time_to_sleep> " RESET, 2);
		ft_putstr_fd(RED "[nbr_of_times_each_philosopher_must_eat]\n" RESET, 2);
		return (0);
	}
	if (code == ERR_NON_NUMERIC)
		return (ft_putstr_fd(RED "[ERROR 102] Non numeric\n" RESET, 2), 0);
	if (code == ERR_NEGATIVE_VALUE)
		return (ft_putstr_fd(RED "[ERROR 103] Negative number\n" RESET, 2), 0);
	if (code == ERR_OUT_OF_LIMITS)
		return (ft_putstr_fd(RED "[ERROR 104] Out of limits\n" RESET, 2), 0);
	if (code == ERR_NULL_VALUE)
		return (ft_putstr_fd(RED "[ERROR 105] NULL value\n" RESET, 2), 0);
	if (code == ERR_EMPTY_VALUE)
		return (ft_putstr_fd(RED "[ERROR 106] Empty value\n" RESET, 2), 0);
	return (0);
}

int	error_messages_malloc(int code)
{
	if (code == ERR_MALLOC_SILVERWARE)
		return (ft_putstr_fd(RED "[ERROR 203] Malloc error\n" RESET, 2), 0);
	return (0);
}

int	error_messages_init(int code)
{
	if (code == ERR_MUTEX_INIT)
		return (ft_putstr_fd(RED "[ERROR 401] Mutex init\n" RESET, 2), 0);
	return (0);
}
