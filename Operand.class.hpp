#pragma once

#include "IOperand.hpp"
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Factory.class.hpp"

template <typename T>
class Operand : public IOperand
{
private:
    T _val;
    eOperandType _type;
    size_t _precision;
    std::string _str;
    std::string _strOut;

public:
    Operand(T val) : _val(val)
    {
        if (typeid(T) == typeid(int8_t))
        {
            _type = Int8;
            _precision = 0;
        }
        else if (typeid(T) == typeid(int16_t))
        {
            _type = Int16;
            _precision = 0;
        }
        else if (typeid(T) == typeid(int32_t))
        {
            _type = Int32;
            _precision = 0;
        }
        else if (typeid(T) == typeid(float))
        {
            _type = Float;
            _precision = 7;
        }
        else if (typeid(T) == typeid(double))
        {
            _type = Double;
            _precision = 14;
        }

        if (this->_type < Float)
        {
            this->_str = std::to_string(val);
            this->_strOut = std::to_string(val);
        }
        else
        {
            std::stringstream set(std::stringstream::out);
            set << std::fixed << std::setprecision(this->_precision) << this->_val;
            this->_str = set.str();
            std::stringstream setOut(std::stringstream::out);
            setOut << std::fixed << std::setprecision(2) << this->_val;
            this->_strOut = setOut.str();
        }
    }
    Operand(Operand const &val)
    {
        *this = val;
    }
    Operand &operator=(Operand const &val)
    {
        if (this != &val)
        {
            this->_val = val._val;
            this->_type = val._type;
            this->_precision = val._precision;
            this->_str = val._str;
            this->_strOut = val._strOut;
        }
        return *this;
    }
    ~Operand(void)
    {
    }

    int getPrecision(void) const
    {
        return this->_precision;
    }

    eOperandType getType(void) const
    {
        return this->_type;
    }

    std::string const &toString(void) const
    {
        return this->_str;
    }
    std::string const &toStringOut(void) const
    {
        return this->_strOut;
    }

    IOperand const *operator+(IOperand const &rhs) const
    {
        eOperandType tmpType = (this->_type >= rhs.getType() ? this->_type : rhs.getType());

        if (tmpType < Float)
        {
            return Factory().createOperand(tmpType, std::to_string(this->_val + std::stoll(rhs.toString())));
        }
        else
        {
            return Factory().createOperand(tmpType, std::to_string(this->_val + std::stold(rhs.toString())));
        }
    }

    IOperand const *operator-(IOperand const &rhs) const
    {
        eOperandType tmpType = (this->_type >= rhs.getType() ? this->_type : rhs.getType());

        if (tmpType < Float)
        {
            return Factory().createOperand(tmpType, std::to_string(this->_val - std::stoll(rhs.toString())));
        }
        else
        {
            return Factory().createOperand(tmpType, std::to_string(this->_val - std::stold(rhs.toString())));
        }
    }

    IOperand const *operator*(IOperand const &rhs) const
    {
        eOperandType tmpType = (this->_type >= rhs.getType() ? this->_type : rhs.getType());

        if (tmpType < Float)
        {
            return Factory().createOperand(tmpType, std::to_string(this->_val * std::stoll(rhs.toString())));
        }
        else
        {
            return Factory().createOperand(tmpType, std::to_string(this->_val * std::stold(rhs.toString())));
        }
    }

    IOperand const *operator/(IOperand const &rhs) const
    {
        eOperandType tmpType = (this->_type >= rhs.getType() ? this->_type : rhs.getType());
        if (std::stold(rhs.toString()) == 0)
            throw Exceptions::DivisionByZeroError();
        else
        {
            if (tmpType < Float)
            {
                return Factory().createOperand(tmpType, std::to_string(this->_val / std::stoll(rhs.toString())));
            }
            else
            {
                return Factory().createOperand(tmpType, std::to_string(this->_val / std::stold(rhs.toString())));
            }
        }
    }

    IOperand const *operator%(IOperand const &rhs) const
    {
        eOperandType tmpType = (this->_type >= rhs.getType() ? this->_type : rhs.getType());
        if (std::stold(rhs.toString()) == 0)
            throw Exceptions::DivisionByZeroError();
        else
        {
            if (tmpType < Float)
            {
                return Factory().createOperand(tmpType, std::to_string(static_cast<int64_t>(this->_val) % std::stoll(rhs.toString())));
            }
            else
            {
                return Factory().createOperand(tmpType, std::to_string(fmod(this->_val, std::stold(rhs.toString()))));
            }
        }
    }

    bool operator==(IOperand const &rhs) const
    {
        eOperandType tmpType = (this->_type >= rhs.getType() ? this->_type : rhs.getType());

        if (tmpType < Float)
        {
            return static_cast<int32_t>(this->_val) == std::stoi(rhs.toString());
        }
        else if (tmpType == Float)
        {
            return static_cast<float>(this->_val) == std::stof(rhs.toString());
        }
        else
        {
            return static_cast<double>(this->_val) == std::stod(rhs.toString());
        }
    }

    bool operator!=(IOperand const &rhs) const
    {
        eOperandType tmpType = (this->_type >= rhs.getType() ? this->_type : rhs.getType());

        if (tmpType < Float)
        {
            return !(static_cast<int32_t>(this->_val) == std::stoi(rhs.toString()));
        }
        else if (tmpType == Float)
        {
            return !(static_cast<float>(this->_val) == std::stof(rhs.toString()));
        }
        else
        {
            return !(static_cast<double>(this->_val) == std::stod(rhs.toString()));
        }
    }
};
