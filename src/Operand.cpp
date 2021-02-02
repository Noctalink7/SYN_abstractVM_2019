/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** Operand header
*/

#include "../include/Operand.hpp"
#include "../include/Factory.hpp"
#include "../include/Exception.hpp"
#include <iostream>
#include <limits>

template <typename T>
Operand<T>::Operand(eOperandType _type, const std::string &_value)
{
    type = _type;
    value = _value;
}

template <typename T>
std::string Operand<T>::toString(void) const
{
        return this->value;
}

template <typename T>
eOperandType Operand<T>::getType(void) const
{
 	return this->type;
}

template <typename T>
IOperand *Operand<T>::operator+(IOperand const &rhs) const
{
    IOperand *op;
    Factory factory;
    double src = static_cast<double>(stod(this->value));
    double rslt = static_cast<double>(stod(rhs.toString()));
    std::string tmp;

    if ((rslt > 0) && (src > std::numeric_limits<T>::max() + rslt))
        throw Exception("Error: overflow");
    if ((rslt < 0) && (src < -std::numeric_limits<T>::max() + rslt - 1))
        throw Exception("Error: overflow");
    tmp = std::to_string(src + rslt);
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0)
        tmp = tmp.substr(0, tmp.find(".", 0));
    if(tmp.find('.') != std::string::npos) {
        tmp = tmp.substr(0, tmp.find_last_not_of('0')+1);
        if(tmp.find('.') == tmp.size()-1)
            tmp = tmp.substr(0, tmp.size()-1);
    }
    if (this->getPrecision() > rhs.getPrecision())
        op = factory.createOperand(this->getType(), tmp);
    else
        op = factory.createOperand(rhs.getType(), tmp);
    return op;
}

template <typename T>
IOperand *Operand<T>::operator-(IOperand const &rhs) const
{
    IOperand *op;
    Factory factory;
    double src = static_cast<double>(stod(this->value));
    double rslt = static_cast<double>(stod(rhs.toString()));
    std::string tmp;

    if ((rslt > 0) && (src > std::numeric_limits<T>::max() - rslt))
        throw Exception("Error: overflow");
    if ((rslt < 0) && (src < -std::numeric_limits<T>::max() - rslt - 1))
        throw Exception("Error: overflow");
    tmp = std::to_string(rslt - src);
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0)
	tmp = tmp.substr(0, tmp.find(".", 0));
    if(tmp.find('.') != std::string::npos) {
        tmp = tmp.substr(0, tmp.find_last_not_of('0')+1);
        if(tmp.find('.') == tmp.size()-1)
            tmp = tmp.substr(0, tmp.size()-1);        
    }
    if (this->getPrecision() > rhs.getPrecision())
        op = factory.createOperand(this->getType(), tmp);
    else
        op = factory.createOperand(rhs.getType(), tmp);
    return op;
}

template <typename T>
IOperand *Operand<T>::operator*(IOperand const &rhs) const
{
    IOperand *op;
    Factory factory;
    double src = static_cast<double>(stod(this->value));
    double rslt = static_cast<double>(stod(rhs.toString()));
    std::string tmp;

    if ((rslt > 0) && (src * rslt > std::numeric_limits<T>::max()))
        throw Exception("Error: overflow");
    if ((rslt < 0) && (src  * rslt - 1 < -std::numeric_limits<T>::max()))
        throw Exception("Error: overflow");
    tmp = std::to_string(src * rslt);
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0)
	tmp = tmp.substr(0, tmp.find(".", 0));
    if(tmp.find('.') != std::string::npos) {
        tmp = tmp.substr(0, tmp.find_last_not_of('0')+1);
        if(tmp.find('.') == tmp.size()-1)
            tmp = tmp.substr(0, tmp.size()-1);            
    }
    if (this->getPrecision() > rhs.getPrecision())
        op = factory.createOperand(this->getType(), tmp);
    else
        op = factory.createOperand(rhs.getType(), tmp);
    return op;
}

template <typename T>
IOperand *Operand<T>::operator/(IOperand const &rhs) const
{
    IOperand *op;
    Factory factory;
    double src = static_cast<double>(stod(this->value));
    double rslt = static_cast<double>(stod(rhs.toString()));
    std::string tmp;

    if (atof(rhs.toString().c_str()) == 0 || atof(this->toString().c_str()) == 0)
        throw Exception("Error: div by 0");
    if ((rslt > 0) && (src / rslt > std::numeric_limits<T>::max()))
        throw Exception("Error: overflow");
    if ((rslt < 0) && (src / rslt - 1 < -std::numeric_limits<T>::max()))
        throw Exception("Error: overflow");
    tmp = std::to_string(src / rslt);
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0)
        tmp = tmp.substr(0, tmp.find(".", 0));
    if(tmp.find('.') != std::string::npos) {
        tmp = tmp.substr(0, tmp.find_last_not_of('0')+1);
        if(tmp.find('.') == tmp.size()-1)
            tmp = tmp.substr(0, tmp.size()-1);
    }
    if (this->getPrecision() > rhs.getPrecision())
        op = factory.createOperand(this->getType(), tmp);
    else
        op = factory.createOperand(rhs.getType(), tmp);
    return op;
}

template <typename T>
IOperand *Operand<T>::operator%(IOperand const &rhs) const
{
    IOperand *op;
    Factory factory;
    int src = static_cast<int>(stod(this->value));
    int rslt = static_cast<int>(stod(rhs.toString()));
    std::string tmp;

    if (atof(rhs.toString().c_str()) == 0 || atof(this->toString().c_str()) == 0)
        throw Exception("Error: mod by 0");
    if (this->type == FLOAT || rhs.getType() == FLOAT)
        throw Exception("Error: can't mod with float");
    if (type == DOUBLE || rhs.getType() == DOUBLE)
        throw Exception("Error: can't mod double");
    if (type == BIGDECIMAL || rhs.getType() == BIGDECIMAL)
        throw Exception("Error: can't mod BigDecimal");
    if ((rslt > 0) && (src > std::numeric_limits<T>::max() - rslt))
        throw Exception("Error: overflow");
    if ((rslt < 0) && (src < -std::numeric_limits<T>::max() - rslt - 1))
        throw Exception("Error: overflow");
    tmp = std::to_string(src % rslt);
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0)
        tmp = tmp.substr(0, tmp.find(".", 0));
    if (this->getPrecision() > rhs.getPrecision())
        op = factory.createOperand(this->getType(), tmp);
    else
        op = factory.createOperand(rhs.getType(), tmp);
    return op;
}
