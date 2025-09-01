#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "structs.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

bool	is_valid_input(int argc, char *argv[]);

// creation and initialization
int		create_forks(pthread_mutex_t **forks_ptr, int amount);
int		create_philos(t_philosopher **philos_ptr, pthread_mutex_t *forks, t_dinner dinner);
int		init_threads(pthread_t **threads, t_philosopher *philos, t_dinner dinner);
void	join_free_threads(pthread_t *threads, int count);
void	destroy_forks(pthread_mutex_t *forks, int amount);

// routine
void	*even_routine(void *data);
void	*odd_routine(void *data);
void	print_action(size_t index, e_action act);

// time
long	get_elapsed_ms(void);
void	print_elapsed_ms(void);
void	ft_sleep(long time_to_sleep, e_time type);

// utils
int		ft_atoi(const char *nptr);
void	print_dinner(t_dinner dinner);
void	print_philo(t_philosopher philo);
void	print_philos(t_philosopher *philos);


#endif