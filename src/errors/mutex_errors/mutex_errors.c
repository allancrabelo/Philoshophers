/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:41:16 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/23 16:38:08 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	mutex_errors(int code)
{
	if (code == ERR_MUTEX_INIT_TABLE)
		mutex_init_table_error();
	if (code == ERR_MUTEX_INIT_SILVERWARE)
		mutex_init_silverware_error();
}