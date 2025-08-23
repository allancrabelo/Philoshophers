/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_codes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:22:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 16:50:16 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	memory_allocation_silverware_error(void)
{
	printf(BOLD RED "[ERROR 202] Failed to allocate SILVERWARES\n" RESET);
	ft_exit(FT_EXIT_FAILURE);
}

void	memory_allocation_philosophers_error(void)
{
	printf(BOLD RED "[ERROR 2023 Failed to allocate PHILOSOFERS\n" RESET);
	ft_exit(FT_EXIT_FAILURE);
}