/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:21:19 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/11 17:44:58 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	free_silverware(t_table *table, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&table->silverware[i]);
		i++;
	}
	free(table->silverware);
	table->silverware = NULL;
	return ;
}

/**
 * @brief Thread-safe getter for simulation end status
 * 
 * @details Safely retrieves the simulation_ended flag from the table structure
 * using mutex protection to prevent race conditions.
 * 
 * @param table Pointer to the table structure containing simulation state.
 * @return * int 1 if simulation has ended, 0 otherwise.
 */
int getter_thread_safe(t_table *table)
{
	int	result;
	
	pthread_mutex_lock(&table->state_mutex);
	result = table->simulation_ended;
	pthread_mutex_unlock(&table->state_mutex);
	return (result);
}