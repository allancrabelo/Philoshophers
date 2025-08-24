/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:47:15 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/24 15:52:21 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	checker(t_philosophers *philo, t_table *table)
{
	int	i;

	while (!table->end)
	{
		i = -1;
		while (++i < table->number_of_philos)
		{
			if ((get_time() - philo[i].last_meal > table->time_to_die))
			{
				print_status(&philo[i], "died");
				table->end = true;
				break;
			}
		}
	}
	usleep(1000);
}