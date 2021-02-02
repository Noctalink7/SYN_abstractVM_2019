/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** Operand
*/

#ifndef _OPERAND_HPP
#define _OPERAND_HPP

#include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
public:
    Operand(eOperandType _type, const std::string &_value);
    ~Operand() = default;
    virtual eOperandType getType() const;
    virtual std::string toString() const;
    virtual int getPrecision() const;
    IOperand* operator+(const IOperand &rhs) const;
    IOperand* operator-(const IOperand &rhs) const;
    IOperand* operator*(const IOperand &rhs) const;
    IOperand* operator/(const IOperand &rhs) const;
    IOperand* operator%(const IOperand &rhs) const;
protected:
    eOperandType type;
    std::string value;
};

template class Operand<double>;
template class Operand<float>;
template class Operand<int64_t>;
template class Operand<int32_t>;
template class Operand<int16_t>;
template class Operand<int8_t>;

#endif
