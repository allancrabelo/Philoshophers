/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:31:04 by aaugusto          #+#    #+#             */
/*   Updated: 2025/09/14 18:25:19 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// Arguments
# define ERR_INVALID_NUM_ARGS			101
# define ERR_NON_NUMERIC				102
# define ERR_NEGATIVE_VALUE				103
# define ERR_OUT_OF_LIMITS				104
# define ERR_NULL_VALUE					105
# define ERR_EMPTY_VALUE				106

// Memory
# define ERR_MALLOC_FAIL				201
# define ERR_MALLOC_SILVERWARE			202
# define ERR_MALLOC_PHILOSOPHERS		203

// Threads
# define ERR_THREAD_CREATE				301
# define ERR_THREAD_JOIN				302
# define ERR_THREAD_DETACH				303

// Mutex / Semaphore
# define ERR_MUTEX_INIT					401
# define ERR_MUTEX_LOCK					402
# define ERR_MUTEX_UNLOCK				403
# define ERR_MUTEX_DESTROY				404
# define ERR_SEM_OPEN					405
# define ERR_SEM_WAIT					406
# define ERR_SEM_POST					407
# define ERR_MUTEX_INIT_TABLE			408
# define ERR_MUTEX_INIT_SILVERWARE		409

// Simulation
# define ERR_PHILO_DIED					501
# define ERR_MAX_REACHED				502

// [Errors Functions]:
// General
int	error_messages_input(int code);
int	error_messages_init(int code);
int	error_messages_malloc(int code);

// Parsing

// Arguments
#endif