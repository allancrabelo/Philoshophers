/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversion_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:21:14 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/14 17:52:38 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"
#include <limits.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return ( error_messages_input(ERR_OUT_OF_LIMITS),0);
		i++;
	}
	return (sign * result);
}