#include "Main.class.hpp"

Main::Main(void)
{
}

Main::Main(Main &val)
{
    *this = val;
}

Main &Main::operator=(Main const &val)
{
    if (this != &val)
    {
        *this = val;
    }
    return *this;
}

Main::~Main(void)
{
}

void Main::readFromInput(void)
{
    for (std::string line; (std::getline(std::cin, line) && line != ";;");)
        this->_input.push_back(line);
}

void Main::readFromFile(char *file)
{
    std::ifstream fs;

    fs.open(file);
    if (!fs.is_open())
        std::cout << "Exception" << std::endl;
    for (std::string line; std::getline(fs, line);)
    {
        this->_input.push_back(line);
        std::cout << line << " ";
    }
    fs.close();
}

void Main::outInput(void)
{
    std::vector<std::string>::const_iterator it;
    std::vector<std::string>::const_iterator ite = this->_input.end();
    for (it = this->_input.begin(); it != ite; ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}