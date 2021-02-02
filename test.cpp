#include "include/Factory.hpp"
#include <string>
#include <iostream>

int main()
{
    Factory factory;
    std::string test("16");
    std::string test2("8");
    std::string test3("32");
    std::string test4("2.2");
    std::string test5("22.22");
    std::string test6("222.222");
    IOperand *essai;
    IOperand *essai2;
    IOperand *essai3;
    IOperand *essai4;
    IOperand *essai5;
    IOperand *essai6;

    essai = factory.createOperand(INT16, test);
    essai2 = factory.createOperand(INT8, test2);
    essai3 = factory.createOperand(INT32, test3);
    essai4 = factory.createOperand(FLOAT, test4);
    essai5 = factory.createOperand(DOUBLE, test5);
    essai6 = factory.createOperand(BIGDECIMAL, test6);
    std::cout << essai->toString() << std::endl;
    std::cout << essai2->toString() << std::endl;
    std::cout << essai3->toString() << std::endl;
    std::cout << essai4->toString() << std::endl;
    std::cout << essai5->toString() << std::endl;
    std::cout << essai6->toString() << std::endl;
    return 0;
}
