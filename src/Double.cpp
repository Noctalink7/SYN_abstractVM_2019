/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** Double
*/

#include "../include/Double.hpp"

Double::Double(const std::string &value) : Operand(DOUBLE, value)
{
}

eOperandType Double::getType() const
{
        return DOUBLE;
}
