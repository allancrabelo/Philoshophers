/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:54:56 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 08:20:10 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	negative_value(int argument)
{
	if (argument == 1)
		printf(BOLD RED "[ERROR 103] Philosopher is negative\n" RESET);
	else if (argument == 2)
		printf(BOLD RED "[ERROR 103] Time to die is negative\n" RESET);
	else if (argument == 3)
		printf(BOLD RED "[ERROR 103] Time to eat is negative\n" RESET);
	else if (argument == 4)
		printf(BOLD RED "[ERROR 103] Time to sleep is negative\n" RESET);
	else if (argument == 5)
		printf(BOLD RED "[ERROR 103] [Number of meal is negative]\n" RESET);
	ft_exit(FT_EXIT_FAILURE);
}

void	out_of_limits_value(void)
{
	printf(BOLD RED "[ERROR 104] Value out of limits\n" RESET);
	ft_exit(FT_EXIT_FAILURE);
}

void	null_value(int argument)
{
		if (argument == 1)
		printf(BOLD RED "[ERROR 105] Philosopher is NULL\n" RESET);
	else if (argument == 2)
		printf(BOLD RED "[ERROR 105] Time to die is NULL\n" RESET);
	else if (argument == 3)
		printf(BOLD RED "[ERROR 105] Time to eat is NULL\n" RESET);
	else if (argument == 4)
		printf(BOLD RED "[ERROR 105] Time to sleep is NULL\n" RESET);
	else if (argument == 5)
		printf(BOLD RED "[ERROR 105] [Number of meal is NULL]\n" RESET);
	ft_exit(FT_EXIT_FAILURE);
}