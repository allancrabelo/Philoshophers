/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:52:05 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 08:17:01 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	value_errors_arguments(int code, int	argument)
{
	if (code == ERR_NEGATIVE_VALUE)
		negative_value(argument);
	if (code == ERR_OUT_OF_LIMITS)
		out_of_limits_value();
	if (code == ERR_NULL_VALUE)
		null_value(argument);
}