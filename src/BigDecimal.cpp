/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** BigDecimal
*/

#include "../include/BigDecimal.hpp"

BigDecimal::BigDecimal(const std::string &value) : Operand(BIGDECIMAL, value)
{
}

eOperandType BigDecimal::getType() const
{
        return BIGDECIMAL;
}
