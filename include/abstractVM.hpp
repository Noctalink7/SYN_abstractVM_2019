/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** abstractVM
*/

#ifndef ABSTRACTVM_HPP_
#define ABSTRACTVM_HPP_

#include "Parser.hpp"
#include <stack>
#include "IOperand.hpp"
#include <map>

class AbstractVM {
public:
    AbstractVM();
    ~AbstractVM();
    void Input();
    void start(std::list<std::pair<std::string, const IOperand*>> cmds);
    std::list<std::pair<std::string, const IOperand*>> File(std::string filename);
    std::stack<IOperand const *> stack;
private:
    void push(IOperand const *tmp);
    void pop(IOperand const *tmp);
    void dump(IOperand const *tmp);
    void assert(IOperand const *tmp);
    void add(IOperand const *tmp);
    void sub(IOperand const *tmp);
    void mul(IOperand const *tmp);
    void div(IOperand const *tmp);
    void mod(IOperand const *tmp);
    void dup(IOperand const *tmp);
    void swap(IOperand const *tmp);
    void print(IOperand const *tmp);
    void clear(IOperand const *tmp);
    void exit(IOperand const *tmp);
    void process(std::string cmd, const IOperand *op);
    void store(const IOperand *tmp);
    void load(const IOperand *tmp);
    std::map<std::string, void (AbstractVM::*)(IOperand const *)> ptrs;
    std::map<int, const IOperand*> registers;
};

void readlist(std::list<std::pair<std::string, const IOperand*>> list);

#endif /* !ABSTRACTVM_HPP_ */
