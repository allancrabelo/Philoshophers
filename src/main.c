/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:57:24 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/25 11:32:40 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table			table;
	pthread_mutex_t	*silverware;
	t_philosophers	*philos;

	parser(argc, argv);
	init_table(&table, argv);
	silverware = init_silverware(&table);
	philos = init_philos(&table, silverware);
	(void)philos;
	(void)silverware;
	return (0);
}