#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

// Helper function to check if input matches special pseudo-literals
static bool isPseudoLiteral(const std::string& str) {
    return (str == "-inff" || str == "+inff" || str == "nanf" ||
            str == "-inf"  || str == "+inf"  || str == "nan");
}

void ScalarConverter::convert(const std::string& input)
{
    double d = 0.0;
    char* endptr = NULL;

    // 1. Handle Single Char Literals (e.g., 'a', 'c')
    if (input.length() == 1 && !std::isdigit(input[0])) {
        d = static_cast<double>(input[0]);
    }
    else {
        // Prepare string for strtod if input ends with 'f' (e.g. "42.0f")
        std::string strToConvert = input;
        if (strToConvert.length() > 1 && strToConvert[strToConvert.length() - 1] == 'f' && !isPseudoLiteral(strToConvert)) {
            strToConvert = strToConvert.substr(0, strToConvert.length() - 1);
        }

        // Convert string to double
        d = std::strtod(strToConvert.c_str(), &endptr);

        // Validate parsing (if string contains invalid trailing characters or wasn't parsed)
        if (*endptr != '\0' && !isPseudoLiteral(input)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    // 2. Output CHAR
    std::cout << "char: ";
    if (isPseudoLiteral(input) || std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(d))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    // 3. Output INT
    std::cout << "int: ";
    if (isPseudoLiteral(input) || std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }

    // 4. Output FLOAT
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (f == static_cast<int>(f)) {
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    } else {
        std::cout << f << "f" << std::endl;
    }

    // 5. Output DOUBLE
    std::cout << "double: ";
    if (d == static_cast<int>(d)) {
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    } else {
        std::cout << d << std::endl;
    }
}