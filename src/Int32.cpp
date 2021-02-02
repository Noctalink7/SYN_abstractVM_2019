/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** int32
*/

#include "../include/Int32.hpp"

Int32::Int32(const std::string &value) : Operand(INT32, value)
{
}

eOperandType Int32::getType() const
{
        return INT32;
}
