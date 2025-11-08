/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classification_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:39:21 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/17 08:56:43 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

bool	is_digit(char c)
{
	if (c == '+' || c == '-')
		return (true);
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
