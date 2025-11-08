/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utilities_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:37:56 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/08 15:32:50 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Gets current time in milliseconds.
 * 
 * @details Uses gettimeofday() to get current time and converts it to
 * milliseconds. Used for calculating timestamps and measuring durations.
 * 
 * @return Current time in milliseconds since epoch
 */
long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
