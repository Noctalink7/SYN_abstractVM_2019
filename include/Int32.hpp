/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** int32 hpp
*/

#ifndef _INT32_HPP
#define _INT32_HPP

#include "Operand.hpp"

class Int32 : public Operand<int32_t>
{
public:
    Int32(const std::string &value);
    ~Int32() = default;
    eOperandType getType() const;
};

template <>
int Operand<int32_t>::getPrecision() const
{
 	return 0;
}

#endif
