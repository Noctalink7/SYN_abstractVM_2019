/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** int8
*/

#include "../include/Int8.hpp"

Int8::Int8(const std::string &value) : Operand(INT8, value)
{
}

eOperandType Int8::getType() const
{
        return INT8;
}
