/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <sstream>
#include <string>
#include <list>
#include <fstream>
#include <iostream>

class ParseFile {
    public:
        ParseFile() {};
        ~ParseFile() {};

        void setFile(const char *name);
        void printFile(void);
    private:
        std::list<std::string> _file;
        std::string _name;
        std::ifstream _myfile;
};

#endif