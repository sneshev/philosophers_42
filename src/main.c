#include "philosophers.h"

int	prepare_dinner(t_dinner *dinner, int argc, char *argv[])
{
	if (get_elapsed_ms() == -1)
		return (-1);
	dinner->config.philos_count = ft_atoi(argv[1]);
	dinner->config.time_to_die = ft_atoi(argv[2]);
	dinner->config.time_to_eat = ft_atoi(argv[3]);
	dinner->config.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		dinner->config.max_meals = ft_atoi(argv[5]);
	else
		dinner->config.max_meals = -1;
	return (1);
}

// int main()
int	main(int argc, char *argv[])
{
	t_dinner	dinner;
	// int argc = 6;
	// char *argv[argc];
	// argv[0] = "./philosophers";
	// argv[1] = "1";
	// argv[2] = "2";
	// argv[3] = "3";
	// argv[4] = "4";
	// argv[5] = "5";

	if (!is_valid_input(argc, argv))
		return (1);
	if (prepare_dinner(&dinner, argc, argv) == -1)
		return (1);
	usleep(13000);
	print_dinner(dinner);
	printf("ez\n");
}
