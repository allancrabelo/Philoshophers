/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 23:21:51 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/15 00:06:06 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	start(t_table *table, t_philo *philo)
{
	int	i;

	if (table->number_of_philosophers == 1)
	{
		output(philo, SILVERWARE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}