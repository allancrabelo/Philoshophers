/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_codes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:22:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/25 11:49:48 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	memory_allocation_silverware_error(void)
{
	ft_putstr_fd (BOLD RED "[ERROR 202] Failed to allocate SILVERWARES\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}

void	memory_allocation_philosophers_error(void)
{
	ft_putstr_fd (BOLD RED "[ERROR 2023 Failed to allocate PHILOSOFERS\n" RESET, 2);
	ft_exit(FT_EXIT_FAILURE);
}