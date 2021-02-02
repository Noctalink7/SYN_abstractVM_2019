/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** Float hpp
*/

#ifndef _FLOAT_HPP
#define _FLOAT_HPP

#include "Operand.hpp"

class Float : public Operand<float>
{
public:
    Float(const std::string &value);
    ~Float() = default;
    eOperandType getType() const;
};

template <>
int Operand<float>::getPrecision() const
{
        return 7;
}

#endif
