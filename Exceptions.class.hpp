
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

class DivisionByZeroError : std::exception
{
public:
    DivisionByZeroError(void);
    ~DivisionByZeroError(void) throw();
    const char *what(void) const throw();
};

class EmptyStackError : std::exception
{
public:
    EmptyStackError(void);
    ~EmptyStackError(void) throw();
    const char *what(void) const throw();
};

class WrongAssertError : std::exception
{
public:
    WrongAssertError(void);
    ~WrongAssertError(void) throw();
    const char *what(void) const throw();
};

class TooFewElementsError : std::exception
{
public:
    TooFewElementsError(void);
    ~TooFewElementsError(void) throw();
    const char *what(void) const throw();
};

class InvalidTypeError : std::exception
{
public:
    InvalidTypeError(void);
    ~InvalidTypeError(void) throw();
    const char *what(void) const throw();
};

class UnknownInstructionError : std::exception
{
    std::string _error;

public:
    UnknownInstructionError(std::string const &str);
    ~UnknownInstructionError(void) throw();
    const char *what(void) const throw();
};
} // namespace Exceptions