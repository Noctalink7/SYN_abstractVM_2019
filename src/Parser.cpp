/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Parser
*/

#include "../include/Parser.hpp"

void ParseFile::setFile(const char *name)
{
    std::string line;

    this->_name = name;
    this->_myfile = std::ifstream(name);
    while (std::getline(this->_myfile, line)) {
        this->_file.push_back(line);
    }
}

void ParseFile::printFile(void)
{
	for (auto const& i: this->_file) {
		std::cout << i << "\n";
	}
}