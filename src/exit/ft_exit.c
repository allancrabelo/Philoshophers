/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:23:10 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 15:33:17 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	exit_success(void)
{
	exit (EXIT_SUCCESS);
}

static void	exit_failure(void)
{
	exit (EXIT_FAILURE);
}

void	ft_exit(int	code)
{
	if (code == FT_EXIT_SUCESS)
		exit_success() ;
	if (code == FT_EXIT_FAILURE)
		exit_failure() ;
}