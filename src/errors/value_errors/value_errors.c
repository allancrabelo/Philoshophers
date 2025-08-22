/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:52:05 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 17:02:20 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	value_errors_arguments(int code, int	argument)
{
	if (code == ERR_NEGATIVE_VALUE)
		negative_value(argument);
	if (code == ERR_OUT_OF_LIMITS)
		out_of_limits_value();
}