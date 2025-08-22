/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:14:11 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 15:22:52 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	usage_errors_arguments(int	code)
{
	if (code == ERR_INVALID_NUM_ARGS)
		number_of_arguments();
	if (code == ERR_NON_NUMERIC)
		non_numeric();
}