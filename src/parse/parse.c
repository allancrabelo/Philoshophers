/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:23:16 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/19 17:16:26 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Checks if the arguments are empty and returns an error message
 * if they are empty.
 * 
 * @param argv 
 * @return * int 
 */
int	empty_verificator(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (error_messages_input(ERR_EMPTY_VALUE), EXIT_FAILURE);
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
	int		i;
	int		j;
	long	number;

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
		if (number > INT_MAX || number < INT_MIN)
			return (error_messages_input(ERR_OUT_OF_LIMITS), EXIT_FAILURE);
		if (number < 0)
			return (error_messages_input(ERR_NEGATIVE_VALUE), EXIT_FAILURE);
		if (number == 0)
			return (error_messages_input(ERR_NULL_VALUE), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Parser function
 * 
 * @details Hub of diferent parser testers.
 * 
 * @param argc 
 * @param argv 
 * @return * int 
 */
int	parser(int argc, char **argv)
{
	if (empty_verificator(argv))
		return (EXIT_FAILURE);
	if (number_verificator(argc))
		return (EXIT_FAILURE);
	if (digit_verificator(argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
