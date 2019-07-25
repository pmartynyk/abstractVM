
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
    this->_cmd.emplace("dump", &Command::dump);
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

void Command::dump(Main &main, std::string str)
{
    (void)str;
    std::list<IOperand const *>::const_iterator it;
    std::list<IOperand const *>::const_iterator ite = main._stack.end();
    for (it = main._stack.begin(); it != ite; ++it)
        std::cout << this->_typeNumber[(*it)->getType()] << ": " << (*it)->toString() << std::endl;
}

void Command::exit(Main &main, std::string str)
{
    (void)str;
    main._cmdExit = true;
}

void Command::push(Main &main, std::string str)
{
    // std::cout <<"Ok" <<std::endl;
    std::regex checkCmdWithValue(CMD_VAL);
    std::smatch s;
    bool found;
    found = std::regex_search(str, s, checkCmdWithValue);
    std::string val = s[3].str() + s[4].str();
    try
    {
        main._stack.push_back(this->_fac.createOperand(this->_type[s[2]], val));
    }
    catch (const Exceptions::OverflowError &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const Exceptions::UnderflowError &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Command::executeCommand(Main &main, std::string str)
{
    std::regex checkCmd(CMD);
    std::regex checkCmdWithValue(CMD_VAL);
    std::smatch s;
    bool found;

    if (std::regex_match(str, checkCmd))
    {
        found = std::regex_search(str, s, checkCmd);
        (this->*_cmd[s[1]])(main, str);
    }
    else if (std::regex_match(str, checkCmdWithValue))
    {
        found = std::regex_search(str, s, checkCmdWithValue);
        (this->*_cmd[s[1]])(main, str);
    }
}