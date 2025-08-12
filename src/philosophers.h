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
long	ft_gettime(void);
long	get_elapsed_ms(t_dinner dinner);
void	print_elapsed_ms(t_dinner dinner);

// utils
int		ft_atoi(const char *nptr);

// helpers
void	print_dinner(t_dinner dinner);


#endif