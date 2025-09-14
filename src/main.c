/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:57:24 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/14 17:58:40 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philo;

	if (parser(argc, argv))
		return (EXIT_FAILURE);
	if (initializer(argv, &table, &philo))
		return (EXIT_FAILURE);
	return (0);
}