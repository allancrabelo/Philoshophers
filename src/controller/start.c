/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 23:21:51 by aaugusto          #+#    #+#             */
/*   Updated: 2025/10/12 09:50:05 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	dead(t_philo *philo)
{
	int		dead;
	long	cur;
	long	last_meal;

	dead = 0;
	cur = get_time();
	pthread_mutex_lock(&philo->table->state_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->table->state_mutex);
	if (cur - last_meal > philo->table->time_to_die)
	{
		output(philo, DEAD);
		pthread_mutex_lock(&philo->table->state_mutex);
		philo->table->simulation_ended = 1;
		pthread_mutex_unlock(&philo->table->state_mutex);
		dead = 1;
	}
	return (dead);
}

static void	monitor(t_table *table, t_philo *philo)
{
	int	i;
	int	count;

	while (!getter_thread_safe(table))
	{
		i = 0;
		count = 0;
		while (i < table->number_of_philosophers && !getter_thread_safe(table))
		{
			if (dead(&philo[i]))
				return ;
			pthread_mutex_lock(&table->state_mutex);
			if (table->number_of_meals > 0 && philo[i].number_of_meals >= table->number_of_meals)
			{
				count++;
				if (count == table->number_of_philosophers)
					table->simulation_ended = 1;
			}
			pthread_mutex_unlock(&table->state_mutex);
			if (table->simulation_ended)
				return ;
			i++;
		}
		usleep(10);
	}
}


int	start(t_table *table, t_philo *philo)
{
	int	i;
	
	i = 0;
	if (table->number_of_philosophers == 1)
	{
		output(philo, SILVERWARE);
		usleep(table->time_to_die * 1000);
		output(philo, DEAD);
		return(EXIT_FAILURE);
	}
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, loop, &philo[i]) != 0)
			return (ft_putstr_fd("Thread error\n", 2), EXIT_FAILURE);
		i++;
	}
	monitor(table, philo);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (ft_putstr_fd("Thread error\n", 2), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
