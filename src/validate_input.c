#include "philosophers.h"


size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    explain_message()
{
    write(1, "to run philosophers:\n", 21);
    write(1, "./philosophers argv[1] argv[2] argv[3] argv[4] (optional: argv[5])\n", 67);
    write(1, "where: \n", 8);
    write(1, "argv[1] -> number of philosophers\n", 34);
    write(1, "argv[2] -> time to die (miliseconds)\n", 37);
    write(1, "argv[3] -> time to eat (miliseconds)\n", 37);
    write(1, "argv[4] -> time to sleep (miliseconds)\n", 39);
    write(1, "argv[5] (optional) -> number of meals\n", 38);
}

void    positive_int_message(char *arg_name)
{
    write(1, "WARNING: Argument \"", 19);
    write(1, arg_name, ft_strlen(arg_name));
    write(1, "\" should be a positive int\n",27);
}

int ft_isdigit(int c)
{
        if (c < '0')
                return (0);
        if (c > '9')
                return (0);
        return (2048);
}

bool    is_positive_int(char *str)
{
    const char  *int_max = "2147483647";
    int         i;

    while (*str == '+')
        str++;
    if (!*str)
        return (false);
    while (*str == '0')
        str++;
    i = 0;
    if (*str > '2')
        return (false);
    while (int_max[i] && str[i] == int_max[i])
    {
        i++;
        if (str[i] > int_max[i])
            return (false);
    }
    while (str[i] && int_max[i] && ft_isdigit(str[i]))
        i++;
    if (str[i])
        return (false);
    return (true);
}

bool    is_valid_input(int argc, char *argv[])
{
    if (argc < 5 || argc > 6)
        return (explain_message(), false);
    if (!is_positive_int(argv[1]))
        return (positive_int_message("number of philosophers"), false);
    if (!is_positive_int(argv[2]))
        return (positive_int_message("time to die"), false);
    if (!is_positive_int(argv[3]))
        return (positive_int_message("time to eat"), false);
    if (!is_positive_int(argv[4]))
        return (positive_int_message("time to sleep"), false);
    if (argc == 6 && !is_positive_int(argv[5]))
        return (positive_int_message("number of meals"), false);
    return (true);
}
