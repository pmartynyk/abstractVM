#include "Main.class.hpp"
#include "Operand.class.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Main mainClass;

    try
    {
        if (ac == 1)
            mainClass.readFromInput();
        else if (ac == 2)
            mainClass.readFromFile(av[1]);
        if (!mainClass.validateInput())
            return 0;
        mainClass.calculate();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}