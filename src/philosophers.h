#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "structs.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

bool	is_valid_input(int argc, char *argv[]);

// forks
int		create_forks(pthread_mutex_t **forks_ptr, int amount);
void	destroy_forks(pthread_mutex_t *forks, int amount);

// time
long	get_elapsed_ms(void);
void	print_elapsed_ms(void);
void	ft_sleep(long time_to_sleep, e_time type);

// utils
int		ft_atoi(const char *nptr);

// helpers
void	print_dinner(t_dinner dinner);


#endif