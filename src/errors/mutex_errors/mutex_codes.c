/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:40:57 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/25 11:49:10 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	mutex_init_table_error(void)
{
	ft_putstr_fd (BOLD RED "[ERROR 408] Failed to create TABLE mutex\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}

void	mutex_init_silverware_error(void)
{
	ft_putstr_fd (BOLD RED "[ERROR 409] Failed to create SILVERWARE mutex\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}