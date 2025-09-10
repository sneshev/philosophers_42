/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:14:49 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:24:39 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>

# define LEFT 0
# define RIGHT 1

typedef enum s_state
{
	ALIVE,
	DONE,
	DEAD
}	t_state;

typedef struct s_state_struct
{
	pthread_mutex_t	lock;
	t_state			val;
}	t_state_struct;

typedef enum s_time
{
	SEC,
	MILLISEC,
	MICROSEC
}	t_time;

typedef struct s_config
{
	long	start_ms;
	int		philos_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_meals;
}	t_config;

typedef struct s_meal_last
{
	pthread_mutex_t	lock;
	long			val;
}	t_meal_last;

typedef struct s_bool_mutx
{
	pthread_mutex_t	lock;
	bool			val;
}	t_bool_mutx;

typedef struct s_philosopher
{
	size_t			index;
	t_state_struct	state;
	t_config		config;
	pthread_mutex_t	*fork[2];
	t_bool_mutx		*sbdy_died;
	t_meal_last		meal_last;
	int				meals_eaten;
}	t_philosopher;

typedef struct s_dinner
{
	t_config	config;
	t_bool_mutx	sbdy_died;
}	t_dinner;

typedef enum s_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_action;

#endif
