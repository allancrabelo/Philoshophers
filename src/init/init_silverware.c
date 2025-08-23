/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_silverware.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:06:14 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 16:19:49 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	free_silverware(pthread_mutex_t *silverware, int end)
{
	int	i;

	i = 0;
	while (i <= end)
	{
		pthread_mutex_destroy(&silverware[i]);
		i++;
	}
	free(silverware);
}

pthread_mutex_t	*init_silverware(t_table *table)
{
	pthread_mutex_t	*silverware;
	int				i;

	i = 0;
	silverware = malloc(table->number_of_philos * sizeof(pthread_mutex_t));
	if (!silverware)
		memory_allocation_error(ERR_MALLOC_SILVERWARE);
	while (i < table->number_of_philos)
	{
		if (pthread_mutex_init(&silverware[i], NULL) != 0)
		{
			free_silverware(silverware, i);
			mutex_errors(ERR_MUTEX_INIT_SILVERWARE);
		}
		i++;
	}
	return (silverware);
}