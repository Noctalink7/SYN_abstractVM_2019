/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** IOperand
*/

#ifndef _IOPERAND_HPP
#define _IOPERAND_HPP

#include <string>

typedef enum eOperandType
{
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL,
} eOperandType;

class IOperand
{
public:
    virtual std::string toString() const = 0;
    virtual eOperandType getType() const = 0;
    virtual int getPrecision() const = 0;
    virtual IOperand* operator+(const IOperand &rhs) const = 0;
    virtual IOperand* operator-(const IOperand &rhs) const = 0;
    virtual IOperand* operator*(const IOperand &rhs) const = 0;
    virtual IOperand* operator/(const IOperand &rhs) const = 0;
    virtual IOperand* operator%(const IOperand &rhs) const = 0;
    virtual ~IOperand() {}
};

#endif
