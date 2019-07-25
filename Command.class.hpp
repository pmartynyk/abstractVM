
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <regex>
#include "Regular.hpp"
#include "Factory.class.hpp"
#include "IOperand.hpp"

class Main;

class Command
{
private:
    std::map<std::string, void (Command::*)(Main &, std::string)> _cmd;
    std::map<std::string, eOperandType> _type;
    std::map<int, std::string> _typeNumber;
    Factory _fac;

public:
    Command(void);
    Command(Command const &val);
    Command &operator=(Command const &val);
    ~Command(void);

    void executeCommand(Main &main, std::string str);
    
    void dump(Main &main, std::string str);
    void exit(Main &main, std::string str);
    void push(Main &main, std::string str);
};
