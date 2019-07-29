
#include "Main.class.hpp"
#include "Operand.class.hpp"

Main::Main(void)
{
    this->_cmdExit = false;
}

Main::Main(Main &val)
{
    *this = val;
}

Main &Main::operator=(Main const &val)
{
    if (this != &val)
    {
        this->_input = val._input;
        this->_isExit = val._isExit;
    }
    return *this;
}

Main::~Main(void)
{
    std::list<IOperand const *>::const_iterator it;
    std::list<IOperand const *>::const_iterator ite = this->_stack.end();
    for (it = this->_stack.begin(); it != ite; ++it)
        delete *it;
}

void Main::readFromInput(void)
{
    for (std::string line; (std::getline(std::cin, line) && line != ";;");)
        this->_input.push_back(line);
}

std::string &Main::getCurString(void)
{
    return this->_curString;
}

void Main::readFromFile(char *file)
{
    std::ifstream fs;

    fs.open(file);
    if (!fs.is_open())
        throw Exceptions::CanNotOpenFile(file);
    for (std::string line; std::getline(fs, line);)
        this->_input.push_back(this->trim(line));
    fs.close();
}

bool Main::validateInput(void)
{
    std::regex checkCmd(CMD);
    std::regex checkCmdWithValue(CMD_VAL);
    std::regex checkComment(CMT);
    std::regex checkEmpty(EMPTY);
    std::regex checkExit(EXIT);
    bool res = true;
    int line = 1;

    std::list<std::string>::const_iterator it;
    std::list<std::string>::const_iterator ite = this->_input.end();
    for (it = this->_input.begin(); it != ite; ++it)
    {
        try
        {
            if (std::regex_match(*it, checkComment) || std::regex_match(*it, checkEmpty))
            {
                line++;
                continue;
            }
            else if (!std::regex_match(*it, checkCmd) &&
                     !std::regex_match(*it, checkCmdWithValue))
            {
                res = false;
                throw Exceptions::SyntaxError(line, *it);
            }
        }
        catch (const Exceptions::SyntaxError &e)
        {
            std::cerr << e.what() << '\n';
        }
        if (std::regex_match(*it, checkExit))
            this->_isExit = true;
        line++;
    }
    if (this->_isExit == false)
        throw Exceptions::NoExitCommand();
    return res;
}

void Main::calculate(void)
{
    std::regex checkCmd(CMD);
    std::regex checkCmdWithValue(CMD_VAL);

    std::list<std::string>::const_iterator it;
    std::list<std::string>::const_iterator ite = this->_input.end();
    for (it = this->_input.begin(); (it != ite && !this->_cmdExit); ++it)
    {
        if (std::regex_match(*it, checkCmd) || std::regex_match(*it, checkCmdWithValue))
        {
            try
            {
                this->_curString = *it;
                Command().executeCommand(*this);
            }
            catch (const Exceptions::EmptyStackError &e)
            {
                std::cerr << e.what() << '\n';
            }
            catch (const Exceptions::DivisionByZeroError &e)
            {
                std::cerr << e.what() << '\n';
            }
            catch (const Exceptions::WrongAssertError &e)
            {
                std::cerr << e.what() << '\n';
            }
            catch (const Exceptions::TooFewElementsError &e)
            {
                std::cerr << e.what() << '\n';
            }
            catch (const Exceptions::UnderflowError &e)
            {
                std::cerr << e.what() << '\n';
            }
            catch (const Exceptions::OverflowError &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

std::string Main::ltrim(const std::string &s)
{
    return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string Main::rtrim(const std::string &s)
{
    return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string Main::trim(const std::string &s)
{
    return ltrim(rtrim(s));
}