/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:54:56 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/25 11:48:07 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	negative_value(int argument)
{
	if (argument == 1)
		ft_putstr_fd (BOLD RED "[ERROR 103] Philosopher is negative\n" RESET, 2);
	else if (argument == 2)
		ft_putstr_fd (BOLD RED "[ERROR 103] Time to die is negative\n" RESET, 2);
	else if (argument == 3)
		ft_putstr_fd (BOLD RED "[ERROR 103] Time to eat is negative\n" RESET, 2);
	else if (argument == 4)
		ft_putstr_fd (BOLD RED "[ERROR 103] Time to sleep is negative\n" RESET, 2);
	else if (argument == 5)
		ft_putstr_fd (BOLD RED "[ERROR 103] [Number of meal is negative]\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}

void	out_of_limits_value(void)
{
	ft_putstr_fd (BOLD RED "[ERROR 104] Value out of limits\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}

void	null_value(int argument)
{
		if (argument == 1)
		ft_putstr_fd (BOLD RED "[ERROR 105] Philosopher is NULL\n" RESET, 2);
	else if (argument == 2)
		ft_putstr_fd (BOLD RED "[ERROR 105] Time to die is NULL\n" RESET, 2);
	else if (argument == 3)
		ft_putstr_fd (BOLD RED "[ERROR 105] Time to eat is NULL\n" RESET, 2);
	else if (argument == 4)
		ft_putstr_fd (BOLD RED "[ERROR 105] Time to sleep is NULL\n" RESET, 2);
	else if (argument == 5)
		ft_putstr_fd (BOLD RED "[ERROR 105] [Number of meal is NULL]\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}