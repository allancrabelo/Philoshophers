/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:43:41 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 17:19:05 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_philosophers	*init_philos(t_table *table, pthread_mutex_t *silverware)
{
	t_philosophers	*philos;
	int				i;

	i = -1;
	philos = malloc(table->number_of_philos * sizeof(t_philosophers));
	if (!philos)
		memory_allocation_error(ERR_MALLOC_PHILOSOPHERS);
	while (++i < table->number_of_philos)
	{
		philos[i].id_number = i + 1;
		philos[i].meal_number = 0;
		philos[i].right_silverware = &silverware[i];
		philos[i].left_silverware = &silverware[(i + 1) %table->number_of_philos];
		philos[i].last_meal = get_time();
		philos[i].table = table;
	}
	return (philos);
}
