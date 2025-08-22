/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:31:04 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/22 17:03:39 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// Arguments
# define ERR_INVALID_NUM_ARGS	101
# define ERR_NON_NUMERIC		102
# define ERR_NEGATIVE_VALUE		103
# define ERR_OUT_OF_LIMITS		104

// Memory
# define ERR_MALLOC_FAIL		201

// Threads
# define ERR_THREAD_CREATE		301
# define ERR_THREAD_JOIN		302
# define ERR_THREAD_DETACH		303

// Mutex / Semaphore
# define ERR_MUTEX_INIT			401
# define ERR_MUTEX_LOCK			402
# define ERR_MUTEX_UNLOCK		403
# define ERR_MUTEX_DESTROY		404
# define ERR_SEM_OPEN			405
# define ERR_SEM_WAIT			406
# define ERR_SEM_POST			407

// Simulation
# define ERR_PHILO_DIED			501
# define ERR_MAX_REACHED		502

// Exit Codes
# define FT_EXIT_SUCESS			601
# define FT_EXIT_FAILURE		602

// [Errors Functions]:
// General
void	usage_errors_arguments(int	code);
void	number_of_arguments(void);
void	non_numeric(void);
void	value_errors_arguments(int code, int	argument);
void	negative_value(int argument);
void	out_of_limits_value(void);

// Exit
void	ft_exit(int	code);

// Argumets
#endif