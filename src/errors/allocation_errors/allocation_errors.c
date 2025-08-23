/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:23:12 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 16:49:14 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	memory_allocation_error(int code)
{
	if (code == ERR_MALLOC_SILVERWARE)
		memory_allocation_silverware_error();
	if (code == ERR_MALLOC_PHILOSOPHERS)
		memory_allocation_philosophers_error();
}