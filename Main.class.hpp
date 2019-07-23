#pragma once

#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

class Main
{
private:
    std::list<std::string> _input;

public:
    Main(void);
    Main(Main &val);
    Main &operator=(Main const &val);
    ~Main(void);

    void readFromInput(void);
    void readFromFile(char *file);

    bool validateInput(void);

    std::string ltrim(const std::string &s);
    std::string rtrim(const std::string &s);
    std::string trim(const std::string &s);

    void outInput(void);
};