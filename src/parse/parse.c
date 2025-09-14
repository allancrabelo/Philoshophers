/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:23:16 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/14 17:52:17 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	empty_verificator(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return(error_messages_input(ERR_EMPTY_VALUE), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	number_verificator(int argc)
{
	if (argc != 5 && argc != 6)
		return (error_messages_input(ERR_INVALID_NUM_ARGS), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	digit_verificator(char **argv)
{
	int	i;
	int	j;
	int	number;

	i = 1 ;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_digit(argv[i][j]) == false)
				return (error_messages_input(ERR_NON_NUMERIC), EXIT_FAILURE);
			j++;
		}
		number = ft_atoi(argv[i]);
		if (number < 0)
			return (error_messages_input(ERR_NEGATIVE_VALUE), EXIT_FAILURE);
		if (number == 0)
			return (error_messages_input(ERR_NULL_VALUE), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parser(int argc,char **argv)
{
	if (empty_verificator(argv))
		return (EXIT_FAILURE);
	if (number_verificator(argc))
		return (EXIT_FAILURE);
	if (digit_verificator(argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}