/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** int16
*/

#include "../include/Int16.hpp"

Int16::Int16(const std::string &value) : Operand(INT16, value)
{
}

eOperandType Int16::getType() const
{
        return INT16;
}
