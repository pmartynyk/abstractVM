
#include "Exceptions.class.hpp"

const char *Exceptions::NoExitCommand::what(void) const throw()
{
    return ("ERROR: The program doesn’t have an exit instruction");
}

Exceptions::CanNotOpenFile::CanNotOpenFile(std::string const &str)
{
    this->_error = "ERROR: Can't open file \"" + str + "\"";
}

Exceptions::CanNotOpenFile::~CanNotOpenFile(void) throw()
{
}

const char *Exceptions::CanNotOpenFile::what(void) const throw()
{
    return (this->_error.c_str());
}

Exceptions::SyntaxError::SyntaxError(int line, std::string const &str)
{
    this->_error = "ERROR: In line " + std::to_string(line) + " mistake \"" + str + "\"";
}

Exceptions::SyntaxError::~SyntaxError(void) throw()
{
}

const char *Exceptions::SyntaxError::what(void) const throw()
{
    return (this->_error.c_str());
}

Exceptions::OverflowError::OverflowError(std::string const &str)
{
    this->_error = "ERROR: OverflowError for " + str;
}

Exceptions::OverflowError::~OverflowError(void) throw()
{
}

const char *Exceptions::OverflowError::what(void) const throw()
{
    return (this->_error.c_str());
}

Exceptions::UnderflowError::UnderflowError(std::string const &str)
{
    this->_error = "ERROR: UnderlowError for " + str;
}

Exceptions::UnderflowError::~UnderflowError(void) throw()
{
}

const char *Exceptions::UnderflowError::what(void) const throw()
{
    return (this->_error.c_str());
}

Exceptions::DivisionByZeroError::DivisionByZeroError()
{
}

Exceptions::DivisionByZeroError::~DivisionByZeroError(void) throw()
{
}

const char *Exceptions::DivisionByZeroError::what(void) const throw()
{
    return ("ERROR: Division by zero.");
}

Exceptions::EmptyStackError::EmptyStackError()
{
}

Exceptions::EmptyStackError::~EmptyStackError(void) throw()
{
}

const char *Exceptions::EmptyStackError::what(void) const throw()
{
    return ("ERROR: Stack is empty.");
}

Exceptions::WrongAssertError::WrongAssertError()
{
}

Exceptions::WrongAssertError::~WrongAssertError(void) throw()
{
}

const char *Exceptions::WrongAssertError::what(void) const throw()
{
    return ("ERROR: An assert instruction is not true.");
}

Exceptions::TooFewElementsError::TooFewElementsError()
{
}

Exceptions::TooFewElementsError::~TooFewElementsError(void) throw()
{
}

const char *Exceptions::TooFewElementsError::what(void) const throw()
{
    return ("ERROR: The stack is composed of strictly less that two values when an arithmetic instruction is executed.");
}