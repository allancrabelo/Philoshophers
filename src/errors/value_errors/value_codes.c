/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:54:56 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 16:22:21 by aaugusto         ###   ########.fr       */
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
	ft_exit(FT_EXIT_FAILURE);
}
