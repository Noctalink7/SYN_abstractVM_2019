/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** test1
*/

#include "../include/unit_tests.hpp"

Test(test_abstractVM, AbstractVM)
{
    AbstractVM test;
    std::list<std::string> tmp = test.File("test/example.avm");
    std::list<std::string> fnl = {"push", "push",
                                "add", "push",
                                "mul", "push", "push",
                                "dump", "pop", "assert", "exit"};

    cr_assert_eq(fnl, tmp);
}
