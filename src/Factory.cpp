/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** factory
*/

#include "../include/Operand.hpp"
#include "../include/Factory.hpp"
#include "../include/Int16.hpp"
#include "../include/Int8.hpp"
#include "../include/Int32.hpp"
#include "../include/Float.hpp"
#include "../include/Double.hpp"
#include "../include/BigDecimal.hpp"

IOperand *Factory::createOperand(eOperandType type, std::string &value)
{
    switch(type) {
    case INT8:
        return createInt8(value);
    case INT16:
        return createInt16(value);
    case INT32:
        return createInt32(value);
    case FLOAT:
        return createFloat(value);
    case DOUBLE:
        return createDouble(value);
    case BIGDECIMAL:
        return createBigDecimal(value);
    }
    return createInt32(value);
}

IOperand *Factory::createOperand(std::string type, std::string &value)
{
    const std::string int8("int8");
    const std::string int16("int16");
    const std::string int32("int32");
    const std::string Float("float");
    const std::string Double("double");
    const std::string Bigdecimal("bigdecimal");

    if (type == int8)
        return createInt8(value);
    else if (type == int16)
        return createInt16(value);
    else if (type == int32)
        return createInt32(value);
    else if (type == Float)
        return createFloat(value);
    else if (type == Double)
        return createDouble(value);
    else if (type == Bigdecimal)
        return createBigDecimal(value);
    return createInt32(value);
}

IOperand *Factory::createInt8(const std::string &value)
{
    return (new Int8(value));
}

IOperand *Factory::createInt16(const std::string &value)
{
    return (new Int16(value));
}

IOperand *Factory::createInt32(const std::string &value)
{
    return (new Int32(value));
}

IOperand *Factory::createFloat(const std::string &value)
{
    return (new Float(value));
}

IOperand *Factory::createDouble(const std::string &value)
{
    return (new Double(value));
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
    return (new BigDecimal(value));
}
