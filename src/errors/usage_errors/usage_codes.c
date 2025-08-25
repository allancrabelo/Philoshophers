/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:18:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/25 11:46:34 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	number_of_arguments(void)
{
	ft_putstr_fd (BOLD RED"[ERROR 101]: Invalid argument number\n" RESET, 2);
	ft_putstr_fd (BOLD RED"Usage: ./philo <num_philos> <time_to_die>" RESET, 2);
	ft_putstr_fd (BOLD RED " <time_to_eat> <time_to_sleep>" RESET, 2);
	ft_putstr_fd (BOLD RED " [number_of_times_each_philosopher_must_eat]\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}

void	non_numeric(void)
{
	ft_putstr_fd (BOLD RED"[ERROR 102]: Non numeric argument\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}