/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:57:24 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 17:42:48 by aaugusto         ###   ########.fr       */
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

	return (0);
}