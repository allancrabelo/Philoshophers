/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:18:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 10:43:55 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

int	number_of_arguments(void)
{
	printf (BOLD RED"[ERROR 101]: Invalid argument number\n" RESET);
	printf (BOLD RED"Usage: ./philo [num_philos] [time_to_die]" RESET);
	printf (BOLD RED " [time_to_eat] [time_to_sleep]\n" RESET);
	return (1);
}

int	non_numeric(void)
{
	printf (BOLD RED"[ERROR 102]: Non numeric argument\n" RESET);
	return (1);
}