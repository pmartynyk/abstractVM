
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <regex>
#include "Regular.hpp"
// #include "Main.class.hpp"

class Main;

class Command
{
private:
    // std::map<std::string, void (Command::*)(Main &, std::string)> _cmd;

public:
    Command(void);
    Command(Command const &val);
    Command &operator=(Command const &val);
    ~Command(void);

    void executeCommand(Main & main, std::string str);

    void push(Main & main, std::string str);
};
