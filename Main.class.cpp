
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
        this->_input.push_back(this->trim(line));
    fs.close();
}

bool Main::validateInput(void)
{
    std::regex checkCmd("[[:s:]]*(pop|dump|add|sub|mul|div|mod|print|exit)[[:s:]]*(;[[:w:]]*|[]{0,0})");
    std::regex checkCmdWithValue("[[:s:]]*(push|assert)[[:s:]]+(int8|int16|int32|float|double)[(]([-+]?)([[:d:]]+|[[:d:]]+.[[:d:]]+)[)][[:s:]]*(;.*|[]{0,0})");
    std::regex checkComment("[[:s:]]*;[[:w:]]*[[:s:]]*");
    std::regex checkEmpty("[[:s:]]*");

    std::list<std::string>::const_iterator it;
    std::list<std::string>::const_iterator ite = this->_input.end();
    for (it = this->_input.begin(); it != ite; ++it)
    {
        std::cout << *it << std::endl;
        if (!std::regex_match(*it, checkCmd) &&
            !std::regex_match(*it, checkCmdWithValue) &&
            !std::regex_match(*it, checkComment) &&
            !std::regex_match(*it, checkEmpty))
            return false;
    }
    return true;
}

void Main::outInput(void)
{
    std::list<std::string>::const_iterator it;
    std::list<std::string>::const_iterator ite = this->_input.end();
    for (it = this->_input.begin(); it != ite; ++it)
        std::cout << *it << std::endl;
}

std::string Main::ltrim(const std::string &s)
{
    return std::regex_replace(s, std::regex("^[[:s:]]+"), std::string(""));
}

std::string Main::rtrim(const std::string &s)
{
    return std::regex_replace(s, std::regex("[[:s:]]+$"), std::string(""));
}

std::string Main::trim(const std::string &s)
{
    return ltrim(rtrim(s));
}