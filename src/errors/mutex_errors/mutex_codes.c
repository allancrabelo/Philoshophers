/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:40:57 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 16:39:34 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	mutex_init_table_error(void)
{
	printf(BOLD RED "[ERROR 408] Failed to create TABLE mutex\n" RESET);
	ft_exit(FT_EXIT_FAILURE);
}

void	mutex_init_silverware_error(void)
{
	printf(BOLD RED "[ERROR 409] Failed to create SILVERWARE mutex\n" RESET);
	ft_exit(FT_EXIT_FAILURE);
}