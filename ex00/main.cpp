#include "ScalarConverter.hpp"

void runTest(const std::string &literal)
{
    std::cout << ">>> Testing: [" << literal << "]" << std::endl;
    ScalarConverter::convert(literal);
    std::cout << std::endl;
}


int main(const int argc, const char **argv)
{
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    if (argc == 1)
    {
        std::cout << "==========================================" << std::endl;
        std::cout << "             PRUEBAS AUTOMÁTICA           " << std::endl;
        std::cout << "==========================================" << std::endl << std::endl;

        std::cout << "--- CASOS DEL SUBJECT ---" << std::endl;
        runTest("0");
        runTest("nan");
        runTest("42.0f");

        std::cout << "--- PRUEBAS CON CHAR ---" << std::endl;
        runTest("'a'");
        runTest("a");
        runTest("*");
        runTest("'Z'");

        std::cout << "--- PRUEBAS CON INT ---" << std::endl;
        runTest("42");
        runTest("-42");
        runTest("2147483647");
        runTest("-2147483648");
        runTest("2147483648");

        std::cout << "--- PRUEBAS CON FLOAT Y PSEUDO-LITERALES ---" << std::endl;
        runTest("-4.2f");
        runTest("42.42f");
        runTest("nanf");
        runTest("+inff");
        runTest("-inff");

        std::cout << "--- PRUEBAS CON DOUBLE Y PSEUDO-LITERALES ---" << std::endl;
        runTest("42.42");
        runTest("inf");
        runTest("-inf");

        std::cout << "--- ENTRADAS INVÁLIDAS ---" << std::endl;
        runTest("hola");
        runTest("42.42.42");
        runTest("42ff");

        return 0;
    }
    std::cout << "Usage: ./convert <scalar_literal>" << std::endl;
    return 1;
}