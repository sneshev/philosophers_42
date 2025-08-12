#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "structs.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

bool	is_valid_input(int argc, char *argv[]);

// time
long	get_elapsed_ms(void);
void	print_elapsed_ms(void);
void	ft_sleep(long time_to_sleep, e_time type);

// utils
int		ft_atoi(const char *nptr);

// helpers
void	print_dinner(t_dinner dinner);


#endif