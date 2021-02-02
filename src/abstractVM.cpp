/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
**
*/

#include "../include/abstractVM.hpp"
#include <regex>
#include "../include/Factory.hpp"
#include "../include/Exception.hpp"

AbstractVM::AbstractVM()
{
    this->ptrs["push"] = &AbstractVM::push;
    this->ptrs["pop"] = &AbstractVM::pop;
    this->ptrs["dump"] = &AbstractVM::dump;
    this->ptrs["assert"] = &AbstractVM::assert;
    this->ptrs["add"] = &AbstractVM::add;
    this->ptrs["sub"] = &AbstractVM::sub;
    this->ptrs["mul"] = &AbstractVM::mul;
    this->ptrs["div"] = &AbstractVM::div;
    this->ptrs["mod"] = &AbstractVM::mod;
    this->ptrs["dup"] = &AbstractVM::dup;
    this->ptrs["swap"] = &AbstractVM::swap;
    this->ptrs["print"] = &AbstractVM::print;
    this->ptrs["clear"] = &AbstractVM::clear;
    this->ptrs["exit"] = &AbstractVM::exit;
    this->ptrs["store"] = &AbstractVM::store;
    this->ptrs["load"] = &AbstractVM::load;
}

AbstractVM::~AbstractVM()
{
}

std::list<std::pair<std::string, const IOperand*>> AbstractVM::File(std::string filename)
{
    std::ifstream file;
    std::string ln;
    std::regex regex("^(push|pop|dump|clear|dup|swap|assert|add|sub|mul|div|mod|load|store|print|exit)[\\s]*((int8|int16|int32|float|double|bigdecimal)\\(([-]?[\\d]+[.]?[\\d]*)\\))?");
    std::smatch match;
    std::string cmd;
    std::list<std::pair<std::string, const IOperand*>> cmds; //tmp
    Factory factory;
    std::string tmp;

    file.open(filename.c_str());
    if (file.is_open() == false)
        throw Exception("Error: File doesn't exist");
    while(std::getline(file, ln) && ln != ";;") {
        if (ln != ";;" && (ln[0] == ';' || ln == ""));
        else if (regex_search(ln, match, regex)) {
            cmd = match[1].str();
            if (match[2] == "" && (match[1] == "load" ||
                                   match[1] == "assert" ||
                                   match[1] == "push" ||
                                   match[1] == "store"))
                throw Exception("Error: Bad Input");
            if (match[2].str() != "") {
                if ((match[4].str().find('.') != std::string::npos) &&
                    (match[3] == "int8" ||
                     match[3] == "int32" ||
                     match[3] == "int16"))
                    throw Exception("Error: Bad Input");
                tmp = match[4].str();
                cmds.push_back({cmd, factory.createOperand(match[3].str(), tmp)});
            } else
                cmds.push_back({cmd, NULL});
        } else
            throw Exception("Error: Bad Input");
    }
    return (cmds);
}

void AbstractVM::Input()
{
    std::string file = ".cmd.txt";
    std::ofstream openfile(file);
    std::string ln;

    while(std::getline(std::cin, ln)) {
        if (ln != ";;")
            openfile << ln << std::endl;
        else{
            openfile.close();
            this->start(this->File(file));
            break;
        }
    }
}

void readlist(std::list<std::pair<std::string, const IOperand*>> list)
{
    for (auto const &lists : list) {
        std::cout << (lists).first << std::endl;
        if ((lists).second != NULL)
            std::cout << (lists).second->toString() << std::endl;
    }
}

void AbstractVM::push(const IOperand *tmp)
{
    this->stack.push(tmp);
}

void AbstractVM::pop(const IOperand *tmp)
{
    if (this->stack.empty())
        throw Exception("Error: can't pop empty stack");
    this->stack.pop();
}

void AbstractVM::dump(const IOperand *tmp)
{
    std::stack<const IOperand*> tempo(stack);

    while (!tempo.empty()) {
        std::cout << tempo.top()->toString() << std::endl;
        tempo.pop();
    }
}

void AbstractVM::assert(const IOperand *tmp)
{
    const IOperand *temp = this->stack.top();

    if (tmp->getType() != temp->getType())
        throw Exception("Error: Assert failed (type)");
    if (tmp->toString().compare(temp->toString()) != 0)
        throw Exception("Error: Assert failed (value)");
}

void AbstractVM::add(const IOperand *tmp)
{
    const IOperand *fst;
    const IOperand *sec;

    if (stack.size() < 2)
        throw Exception("Error: not enough minerals");
    fst = stack.top();
    stack.pop();
    sec = stack.top();
    stack.pop();
    this->push(*fst + *sec);
}

void AbstractVM::sub(const IOperand *tmp)
{
    const IOperand *fst;
    const IOperand *sec;

    if (stack.size() < 2)
        throw Exception("Error: not enough minerals");
    fst = stack.top();
    stack.pop();
    sec = stack.top();
    stack.pop();
    this->push(*fst - *sec);

}

void AbstractVM::mul(const IOperand *tmp)
{
    const IOperand *fst;
    const IOperand *sec;

    if (stack.size() < 2)
        throw Exception("Error: not enough minerals");
    fst = stack.top();
    stack.pop();
    sec = stack.top();
    stack.pop();
    this->push(*fst * *sec);
}

void AbstractVM::div(const IOperand *tmp)
{
    const IOperand *fst;
    const IOperand *sec;

    if (stack.size() < 2)
        throw Exception("Error: not enough minerals");
    fst = stack.top();
    stack.pop();
    sec = stack.top();
    stack.pop();
    this->push(*sec / *fst);
}

void AbstractVM::mod(const IOperand *tmp)
{
    const IOperand *fst;
    const IOperand *sec;

    if (stack.size() < 2)
        throw Exception("Error: not enough minerals");
    fst = stack.top();
    stack.pop();
    sec = stack.top();
    stack.pop();
    this->push(*sec % *fst);
}

void AbstractVM::dup(const IOperand *tmp)
{
    Factory fac;
    std::string temp(this->stack.top()->toString());

    if (stack.empty())
        throw Exception("Error: can't dup an empty stack");
    const IOperand *fnl = fac.createOperand(this->stack.top()->getType(), temp);
    this->stack.push(fnl);
}

void AbstractVM::swap(const IOperand *tmp)
{
    Factory fac;
    std::pair<const IOperand *, const IOperand *> pr;

    if (stack.size() < 2)
        throw Exception("Error: can't swap less than 2 elements");
    pr.first = this->stack.top();
    this->stack.pop();
    pr.second = this->stack.top();
    this->stack.pop();
    this->stack.push(pr.first);
    this->stack.push(pr.second);
}

void AbstractVM::print(const IOperand *tmp)
{
    if (this->stack.top()->getType() != eOperandType::INT8)
        throw Exception("Error: Invalid type (not int8)");
    printf("%c\n", std::stoi(this->stack.top()->toString()));
}

void AbstractVM::clear(IOperand const *tmp)
{
    this->stack = std::stack<const IOperand*>();
}

void AbstractVM::exit(const IOperand *tmp)
{
    std::exit(0);
}

void AbstractVM::store(const IOperand *tmp)
{
    int a = atoi(tmp->toString().c_str());

    if (stack.size() == 0)
        throw Exception("Error: Cannot store an empty stack");
    if (a >= 0 && a <= 15) {
        registers[a] = stack.top();
        stack.pop();
    } else
        throw Exception("Error: Can only store in cell between 0 and 15");
}

void AbstractVM::load(const IOperand *tmp)
{
    int	a = atoi(tmp->toString().c_str());

    if (a >= 0 && a <= 15) {
        if (registers[a] != NULL)
            stack.push(registers[a]);
        else
            throw Exception("Error: Cell is empty");
    } else
        throw Exception("Error: Can only load in cell between 0 and 15");
}

void AbstractVM::start(std::list<std::pair<std::string, const IOperand*>> cmds)
{
    for (auto const &cmd : cmds)
        process((cmd).first, (cmd).second);

    if (cmds.size() != 0)
	if (cmds.back().first != "exit")
            throw Exception("Error: Exit is missing");
}

void AbstractVM::process(std::string cmd, const IOperand *op)
{
    ((this)->*(this->ptrs[cmd]))(op);
}
