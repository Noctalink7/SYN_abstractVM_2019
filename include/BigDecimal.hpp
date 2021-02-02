/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** BigDecimal hpp
*/

#ifndef _BIGDECIMAL_HPP
#define _BIGDECIMAL_HPP

#include "Operand.hpp"

class BigDecimal : public Operand<int64_t>
{
public:
    BigDecimal(const std::string &value);
    ~BigDecimal() = default;
    eOperandType getType() const;
};

template <>
int Operand<int64_t>::getPrecision() const
{
        return 200;
}

#endif
