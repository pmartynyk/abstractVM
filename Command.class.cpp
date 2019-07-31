
#include "Command.class.hpp"
#include "Main.class.hpp"

Command::Command(void)
{
    this->_type.emplace("int8", Int8);
    this->_type.emplace("int16", Int16);
    this->_type.emplace("int32", Int32);
    this->_type.emplace("float", Float);
    this->_type.emplace("double", Double);

    this->_typeNumber.emplace(0, "int8");
    this->_typeNumber.emplace(1, "int16");
    this->_typeNumber.emplace(2, "int32");
    this->_typeNumber.emplace(3, "float");
    this->_typeNumber.emplace(4, "double");

    this->_cmd.emplace("push", &Command::push);
    this->_cmd.emplace("add", &Command::add);
    this->_cmd.emplace("sub", &Command::sub);
    this->_cmd.emplace("mul", &Command::mul);
    this->_cmd.emplace("div", &Command::div);
    this->_cmd.emplace("mod", &Command::mod);
    this->_cmd.emplace("assert", &Command::assert);
    this->_cmd.emplace("dump", &Command::dump);
    this->_cmd.emplace("print", &Command::print);
    this->_cmd.emplace("pop", &Command::pop);
    this->_cmd.emplace("exit", &Command::exit);
}

Command::Command(Command const &val)
{
    *this = val;
}

Command &Command::operator=(Command const &val)
{
    if (this != &val)
    {
    }
    return *this;
}

Command::~Command(void)
{
}

void Command::dump(Main &main)
{
    if (main._stack.size() == 0)
        throw Exceptions::EmptyStackError();
    else
    {
        std::list<IOperand const *>::const_iterator it = main._stack.begin();
        std::list<IOperand const *>::const_iterator ite = main._stack.end();
        ite--;
        std::cout << "-----------top----------" << std::endl;
        for (; ite != it; ite--)
            std::cout << this->_typeNumber[(*ite)->getType()] << ": "
                      << "\033[32m" << (*ite)->toStringOut() << "\33[0m" << std::endl;
        std::cout << this->_typeNumber[(*ite)->getType()] << ": "
                  << "\033[32m" << (*ite)->toStringOut() << "\33[0m" << std::endl;

        std::cout << "-----------end----------" << std::endl;
    }
}

void Command::add(Main &main)
{
    if (main._stack.size() < 2)
        throw Exceptions::TooFewElementsError();
    else
    {
        this->_right = main._stack.back();
        main._stack.pop_back();
        this->_left = main._stack.back();
        main._stack.pop_back();
        main._stack.push_back(*this->_left + *this->_right);
        delete this->_right;
        this->_right = nullptr;
        delete this->_left;
        this->_left = nullptr;
    }
}

void Command::sub(Main &main)
{
    if (main._stack.size() < 2)
        throw Exceptions::TooFewElementsError();
    else
    {
        this->_right = main._stack.back();
        main._stack.pop_back();
        this->_left = main._stack.back();
        main._stack.pop_back();
        main._stack.push_back(*this->_left - *this->_right);
        delete this->_right;
        this->_right = nullptr;
        delete this->_left;
        this->_left = nullptr;
    }
}

void Command::mul(Main &main)
{
    if (main._stack.size() < 2)
        throw Exceptions::TooFewElementsError();
    else
    {
        this->_right = main._stack.back();
        main._stack.pop_back();
        this->_left = main._stack.back();
        main._stack.pop_back();
        main._stack.push_back(*this->_left * *this->_right);
        delete this->_right;
        this->_right = nullptr;
        delete this->_left;
        this->_left = nullptr;
    }
}

void Command::div(Main &main)
{
    if (main._stack.size() < 2)
        throw Exceptions::TooFewElementsError();
    else
    {
        this->_right = main._stack.back();
        main._stack.pop_back();
        this->_left = main._stack.back();
        main._stack.pop_back();
        main._stack.push_back(*this->_left / *this->_right);
        delete this->_right;
        this->_right = nullptr;
        delete this->_left;
        this->_left = nullptr;
    }
}

void Command::mod(Main &main)
{
    if (main._stack.size() < 2)
        throw Exceptions::TooFewElementsError();
    else
    {
        this->_right = main._stack.back();
        main._stack.pop_back();
        this->_left = main._stack.back();
        main._stack.pop_back();
        main._stack.push_back(*this->_left % *this->_right);
        delete this->_right;
        this->_right = nullptr;
        delete this->_left;
        this->_left = nullptr;
    }
}

void Command::print(Main &main)
{
    if (main._stack.size() == 0)
        throw Exceptions::EmptyStackError();
    else
    {
        _right = main._stack.back();
        if (this->_right->getType() == Int8)
        {
            int8_t tmp = static_cast<int8_t>(std::stoi(this->_right->toString()));
            std::cout << tmp << std::endl;
            this->_right = nullptr;
        }
        else
        {
            throw Exceptions::InvalidTypeError();
        }
    }
}

void Command::pop(Main &main)
{
    if (main._stack.size() == 0)
        throw Exceptions::EmptyStackError();
    main._stack.pop_back();
}

void Command::exit(Main &main)
{
    main._cmdExit = true;
}

void Command::push(Main &main)
{
    std::regex checkCmdWithValue(CMD_VAL);
    std::smatch s;
    bool found;
    found = std::regex_search(main.getCurString(), s, checkCmdWithValue);
    std::string val = s[3].str() + s[4].str();
    main._stack.push_back(Factory().createOperand(this->_type[s[2]], val));
}

void Command::assert(Main &main)
{
    std::regex checkCmdWithValue(CMD_VAL);
    std::smatch s;
    bool found;
    found = std::regex_search(main.getCurString(), s, checkCmdWithValue);
    std::string val = s[3].str() + s[4].str();
    const IOperand *check = Factory().createOperand(this->_type[s[2]], val);
    if (*check != *main._stack.back())
        throw Exceptions::WrongAssertError();
}

void Command::executeCommand(Main &main)
{
    std::regex checkCmd(CMD);
    std::regex checkCmdWithValue(CMD_VAL);
    std::smatch s;
    bool found;

    if (std::regex_match(main.getCurString(), checkCmd))
    {
        found = std::regex_search(main.getCurString(), s, checkCmd);
        (this->*_cmd[s[1]])(main);
    }
    else if (std::regex_match(main.getCurString(), checkCmdWithValue))
    {
        found = std::regex_search(main.getCurString(), s, checkCmdWithValue);
        (this->*_cmd[s[1]])(main);
    }
}