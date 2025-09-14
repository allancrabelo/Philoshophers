/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:21:19 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/14 18:23:19 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	free_forks(t_table *table, int count)
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