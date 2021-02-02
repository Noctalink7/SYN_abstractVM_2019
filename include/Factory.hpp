/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** header
*/

#ifndef _FACTORY_HPP
#define _FACTORY_HPP

#include "IOperand.hpp"

class Factory
{
public:
    Factory() = default;
    ~Factory() = default;
//    Factory(const Factory&);
    IOperand *createOperand(eOperandType type, std::string &value);
    IOperand *createOperand(std::string type, std::string &value);
protected:
private:
    IOperand *createInt8(const std::string &value);
    IOperand *createInt16(const std::string &value);
    IOperand *createInt32(const std::string &value);
    IOperand *createFloat(const std::string &value);
    IOperand *createDouble(const std::string &value);
    IOperand *createBigDecimal(const std::string &value);
};

#endif
