#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <unistd.h>

typedef enum s_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	e_state;

typedef struct s_philosopher
{
	size_t  index;
	e_state state;

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
	long		time_start;
}	t_dinner;

#endif