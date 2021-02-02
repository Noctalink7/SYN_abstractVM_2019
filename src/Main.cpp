/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Main
*/

#include "../include/abstractVM.hpp"
#include "../include/Exception.hpp"

int main(int ac, const char **av)
{
    AbstractVM VM;

    try {
        if (ac == 2) {
            VM.start(VM.File(av[1]));
        } else
            VM.Input();
    } catch (Exception &e) {
        std::cout << e.err() << std::endl;
        return 84;
    }
    return 0;
}
