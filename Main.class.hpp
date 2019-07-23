#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Main
{
private:

    std::vector<std::string> _input;
    
public:
    Main(void);
    Main(Main & val);
    Main &operator=(Main const & val);
    ~Main(void);

    void readFromInput(void);
    void readFromFile(char *file);
    void outInput(void);
};