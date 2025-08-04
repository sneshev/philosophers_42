#include "philosophers.h"




int main()
// int main(int argc, char *argv[])
{
    int argc = 5;
    char *argv[argc];
    argv[0] = "./philosophers";
    argv[1] = "9999999999";
    argv[2] = "600";
    argv[3] = "21";
    argv[4] = "212320";

    if (!is_valid_input(argc, argv))
        return (1);

}