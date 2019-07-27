
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

    const IOperand *_right;
    const IOperand *_left; 

public:
    Command(void);
    Command(Command const &val);
    Command &operator=(Command const &val);
    ~Command(void);

    void executeCommand(Main &main, std::string str);
    
    void dump(Main &main, std::string str);
    void pop(Main &main, std::string str);
    void print(Main &main, std::string str);
    void exit(Main &main, std::string str);
    void push(Main &main, std::string str);
    void assert(Main &main, std::string str);
    void add(Main &main, std::string str);
    void sub(Main &main, std::string str);
    void mul(Main &main, std::string str);
    void div(Main &main, std::string str);
    void mod(Main &main, std::string str);
};
