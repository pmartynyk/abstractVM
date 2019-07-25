
#pragma once

#include <iostream>
#include <string>

namespace Exceptions
{
class NoExitCommand : public std::exception
{
public:
    const char *what(void) const throw();
};

class CanNotOpenFile : public std::exception
{
    std::string _error;

public:
    CanNotOpenFile(std::string const &str);
    ~CanNotOpenFile(void) throw();
    const char *what(void) const throw();
};

class SyntaxError : std::exception
{
    std::string _error;

public:
    SyntaxError(int line, std::string const &str);
    ~SyntaxError(void) throw();
    const char *what(void) const throw();
};

class OverflowError : std::exception
{
    std::string _error;

public:
    OverflowError(std::string const &str);
    ~OverflowError(void) throw();
    const char *what(void) const throw();
};

class UnderflowError : std::exception
{
    std::string _error;

public:
    UnderflowError(std::string const &str);
    ~UnderflowError(void) throw();
    const char *what(void) const throw();
};
} // namespace Exceptions