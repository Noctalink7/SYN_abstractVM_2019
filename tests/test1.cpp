/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** test1
*/

#include "../include/unit_tests.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Test(test_readlist, readlist, .init = redirect_all_std)
// {
//     readlist({"a", "b", "c"});
//     cr_assert_stdout_eq_str("a\nb\nc\n");
// }