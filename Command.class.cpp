
#include "Command.class.hpp"

Command::Command(void)
{
    // this->_cmd.emplace("push", &Command::push);
}

Command::Command(Command const &val)
{
    *this = val;
}

Command &Command::operator=(Command const &val)
{
    if (this != &val)
    {
    }
    return *this;
}

Command::~Command(void)
{
}

void Command::push(Main & main, std::string str)
{
    (void)main;
    (void)str;
}

void Command::executeCommand(Main & main, std::string str)
{
    (void)main;
    std::regex checkCmd(CMD);
    std::regex checkCmdWithValue(CMD_VAL);
    std::smatch s;
    bool found;

    if (std::regex_match(str, checkCmd))
    {
        found = std::regex_search(str, s, checkCmd);
        // std::cout << s[0] << std::endl;
    }
    else if (std::regex_match(str, checkCmdWithValue))
    {
        found = std::regex_search(str, s, checkCmdWithValue);
        // std::cout << s[2] << std::endl;
    }

    // this->_cmd[]
}