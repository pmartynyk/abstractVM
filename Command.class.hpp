
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
    std::map<std::string, void (Command::*)(Main &)> _cmd;
    std::map<std::string, eOperandType> _type;
    std::map<int, std::string> _typeNumber;

    const IOperand *_right;
    const IOperand *_left;

public:
    Command(void);
    Command(Command const &val);
    Command &operator=(Command const &val);
    ~Command(void);

    void executeCommand(Main &main);

    void dump(Main &main);
    void pop(Main &main);
    void print(Main &main);
    void exit(Main &main);
    void push(Main &main);
    void assert(Main &main);
    void add(Main &main);
    void sub(Main &main);
    void mul(Main &main);
    void div(Main &main);
    void mod(Main &main);
};
