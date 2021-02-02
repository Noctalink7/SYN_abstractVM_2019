/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** Exception
*/

#ifndef _EXCEPTION_HPP
# define _EXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

class Exception : public std::exception
{
public:
    Exception (const std::string &_err) throw();
    ~Exception() throw();
    const char* err() const throw();
    std::string errormsg;
};


#endif
