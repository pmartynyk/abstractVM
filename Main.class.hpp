#pragma once

#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "IOperand.hpp"
#include "Exceptions.class.hpp"
#include "Operand.class.hpp"
#include "Regular.hpp"
#include "Command.class.hpp"

class Main
{
    friend class Command;
private:
    std::list<std::string> _input;
    bool _isExit;
    bool _cmdExit;
    std::list<IOperand const *> _stack;
    Command _cmd;

    std::string ltrim(const std::string &s);
    std::string rtrim(const std::string &s);
    std::string trim(const std::string &s);

public:
    Main(void);
    Main(Main &val);
    Main &operator=(Main const &val);
    ~Main(void);

    void readFromInput(void);
    void readFromFile(char *file);

    bool validateInput(void);

    void calculate(void);

    // void outInput(void);
};