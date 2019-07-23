#include "Main.class.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Main mainClass;

    if (ac == 1)
        mainClass.readFromInput();
    else if (ac == 2)
        mainClass.readFromFile(av[1]);

    // mainClass.outInput();
    return 0;
}