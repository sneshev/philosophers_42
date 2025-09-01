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
}	e_state;

typedef enum s_time
{
	SEC,
	MILLISEC,
	MICROSEC
}	e_time;

typedef struct s_config
{
	long	start_ms;
	int		philos_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_meals;
}	t_config;

typedef struct s_philosopher
{
	size_t  		index;
	e_state 		state; // add mutex ! ! !
	t_config		config;
	pthread_mutex_t	*fork[2];
	long			meal_last;
	int				meals_eaten;
}	t_philosopher;

typedef struct s_dinner
{
	t_config	config;
}	t_dinner;

typedef enum s_action
{
	LFORK,
	RFORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	e_action;

#endif
