
#include "Exceptions.class.hpp"

const char *Exceptions::NoExitCommand::what(void) const throw()
{
    return ("ERROR: No exit command");
}
////////////////
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
////////////////
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
////////////////
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
////////////////
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