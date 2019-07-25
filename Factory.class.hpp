
#pragma once

#include <map>
#include <string>
#include <limits>
#include "IOperand.hpp"
#include "Operand.class.hpp"
#include "Exceptions.class.hpp"

class Factory
{
private:
    std::map<eOperandType, IOperand const *(Factory::*)(std::string const&) const> pointerToFunc;

    IOperand const *createInt8(std::string const &value) const;
    IOperand const *createInt16(std::string const &value) const;
    IOperand const *createInt32(std::string const &value) const;
    IOperand const *createFloat(std::string const &value) const;
    IOperand const *createDouble(std::string const &value) const;

public:
    IOperand const *createOperand(eOperandType type, std::string const &val);

    Factory(void);
    Factory(Factory const &val);
    Factory &operator=(Factory const &val);
    ~Factory(void);
};
