#include "philosophers.h"

int prepare_dinner(t_dinner_info *dinner_info)
{
    if (ft_gettime(&(dinner_info->time_start)) < 0)
        return (-1);

    return (1);
}

// int main()
int main(int argc, char *argv[])
{
    t_dinner_info   dinner_info;
    // int argc = 5;
    // char *argv[argc];
    // argv[0] = "./philosophers";
    // argv[1] = "1234567890";
    // argv[2] = "2148000000";
    // argv[3] = "21";
    // argv[4] = "212320";

    if (!is_valid_input(argc, argv))
        return (1);
    if (prepare_dinner(&dinner_info) == -1)
        return (1);
    sleep(1);
    usleep(10000);
    ft_gettime(&(dinner_info.time_now));
    print_elapsed_ms(dinner_info.time_start, dinner_info.time_now);
    printf("ez\n");
}
