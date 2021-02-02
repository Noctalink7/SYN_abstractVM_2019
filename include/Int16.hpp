/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** int16 hpp
*/

#ifndef _INT16_HPP
#define _INT16_HPP

#include "Operand.hpp"

class Int16 : public Operand<int16_t>
{
public:
    Int16(const std::string &value);
    ~Int16() = default;
    eOperandType getType() const;
};

template <>
int Operand<int16_t>::getPrecision() const
{
 	return 0;
}

#endif
