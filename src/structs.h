#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <unistd.h>

typedef enum s_state
{
	THINKING,
	EATING,
	SLEEPING,
	FINISHED
}	e_state;

typedef enum s_condition
{
	ALIVE,
	DONE,
	DEAD
}	e_condition;

typedef enum s_time
{
	SEC,
	MILLISEC,
	MICROSEC
}	e_time;

typedef struct s_philosopher
{
	size_t  	index;
	e_state 	state;
	e_condition	condition;

}	t_philosopher;

typedef struct s_config
{
	int	philos_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}	t_config;

typedef struct s_dinner
{
	t_config	config;
}	t_dinner;

#endif