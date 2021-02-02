/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** Float
*/

#include "../include/Float.hpp"

Float::Float(const std::string &value) : Operand(FLOAT, value)
{
}

eOperandType Float::getType() const
{
        return FLOAT;
}
