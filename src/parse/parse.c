/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:23:16 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 10:46:15 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	number_verificator(int argc)
{
	if (argc != 5)
		return (usage_errors_arguments(ERR_INVALID_NUM_ARGS), 1);
	return (0);
}

int	argument_verificator(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (&is_digit == false)
				return (usage_errors_arguments(ERR_NON_NUMERIC), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parser(int argc,char **argv)
{
	number_verificator(argc);
	argument_verificator(argv);
	return (1);
}