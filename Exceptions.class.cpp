
#include "Exceptions.class.hpp"

const char *Exceptions::NoExitCommand::what(void) const throw()
{
    return ("ERROR: No exit command");
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