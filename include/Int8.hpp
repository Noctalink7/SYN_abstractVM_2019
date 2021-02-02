/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** int16 hpp
*/

#ifndef _INT8_HPP
#define _INT8_HPP

#include "Operand.hpp"

class Int8 : public Operand<int8_t>
{
public:
    Int8(const std::string &value);
    ~Int8() = default;
    eOperandType getType() const;
};

template <>
int Operand<int8_t>::getPrecision() const
{
 	return 0;
}


#endif
