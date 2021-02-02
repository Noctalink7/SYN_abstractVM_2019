/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** Double hpp
*/

#ifndef _DOUBLE_HPP
#define _DOUBLE_HPP

#include "Operand.hpp"

class Double : public Operand<double>
{
public:
    Double(const std::string &value);
    ~Double() = default;
    eOperandType getType() const;
};

template <>
int Operand<double>::getPrecision() const
{
        return 15;
}


#endif
