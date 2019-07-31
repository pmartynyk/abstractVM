#include "Factory.class.hpp"
#include "Operand.class.hpp"

Factory::Factory(void)
{
    this->pointerToFunc[Int8] = &Factory::createInt8;
    this->pointerToFunc[Int16] = &Factory::createInt16;
    this->pointerToFunc[Int32] = &Factory::createInt32;
    this->pointerToFunc[Float] = &Factory::createFloat;
    this->pointerToFunc[Double] = &Factory::createDouble;
}

Factory::Factory(Factory const &val)
{
    *this = val;
}

Factory &Factory::operator=(Factory const &val)
{
    if (this != &val)
    {
    }
    return (*this);
}

Factory::~Factory(void)
{
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &val)
{
    IOperand const *(Factory::*f)(std::string const &value) const;
    f = pointerToFunc.at(type);
    return ((*this.*f)(val));
}

IOperand const *Factory::createInt8(std::string const &val) const
{

    try
    {
        int64_t res = std::stoll(val);
        if (res > INT8_MAX)
        {
            throw Exceptions::OverflowError("Int8");
        }
        else if (res < INT8_MIN)
        {
            throw Exceptions::UnderflowError("Int8");
        }
        else
            return new Operand<int8_t>(res);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "ERROR: stoll is out of range" << '\n';
        exit(0);
    }
    return nullptr;
}

IOperand const *Factory::createInt16(std::string const &val) const
{
    try
    {
        int64_t res = std::stoll(val);
        if (res > INT16_MAX)
        {
            throw Exceptions::OverflowError("Int16");
        }
        else if (res < INT16_MIN)
        {
            throw Exceptions::UnderflowError("Int16");
        }
        else
            return new Operand<int16_t>(res);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "ERROR: stoll is out of range" << '\n';
        exit(0);
    }
    return nullptr;
}

IOperand const *Factory::createInt32(std::string const &val) const
{
    try
    {
        int64_t res = std::stoll(val);
        if (res > INT32_MAX)
        {
            throw Exceptions::OverflowError("Int32");
        }
        else if (res < INT32_MIN)
        {
            throw Exceptions::UnderflowError("Int32");
        }
        else
            return new Operand<int32_t>(res);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "ERROR: stoll is out of range" << '\n';
        exit(0);
    }
    return nullptr;
}

IOperand const *Factory::createFloat(std::string const &val) const
{
    try
    {
        long double res = std::stold(val);
        if (res > std::numeric_limits<float>::max())
        {
            throw Exceptions::OverflowError("Max positive Float");
        }
        else if (res < -std::numeric_limits<float>::max())
        {
            throw Exceptions::UnderflowError("Max negative Float");
        }
        else if (res > 0 && res < std::numeric_limits<float>::min())
        {
            throw Exceptions::OverflowError("Min positive Float");
        }
        else if (res < 0 && res > -std::numeric_limits<float>::min())
        {
            throw Exceptions::UnderflowError("Min negative Float");
        }
        else
            return new Operand<float>(res);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "ERROR: stold is out of range" << '\n';
        exit(0);
    }
    return nullptr;
}

IOperand const *Factory::createDouble(std::string const &val) const
{
    try
    {
        long double res = std::stold(val);
        if (res > std::numeric_limits<double>::max())
        {
            throw Exceptions::OverflowError("Max positive Double");
        }
        else if (res < -std::numeric_limits<double>::max())
        {
            throw Exceptions::UnderflowError("Max negative Double");
        }
        else if (res > 0 && res < std::numeric_limits<double>::min())
        {
            throw Exceptions::UnderflowError("Min positive Double");
        }
        else if (res < 0 && res > -std::numeric_limits<double>::min())
        {
            throw Exceptions::UnderflowError("Min negative Double");
        }
        else
            return new Operand<double>(res);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "ERROR: stold is out of range" << '\n';
        exit(0);
    }
    return nullptr;
}