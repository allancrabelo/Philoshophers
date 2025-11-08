/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:57:24 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/19 16:37:34 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Program main function
 * 
 * @param argc Number of arguments
 * @param argv Value of arguments
 * @return * int 
 */
int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philo;

	if (parser(argc, argv))
		return (EXIT_FAILURE);
	if (initializer(argv, &table, &philo))
		return (EXIT_FAILURE);
	start(&table, philo);
	free_silverware(&table, table.number_of_philosophers);
	pthread_mutex_destroy(&table.output);
	pthread_mutex_destroy(&table.state_mutex);
	free(philo);
	return (EXIT_SUCCESS);
}
