#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "=== Test 1: Random Generation & Identification ===" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "\n--- Instance " << i + 1 << " ---" << std::endl;
        Base* instance = generate();

        std::cout << "Identify pointer:   ";
        identify(instance);

        std::cout << "Identify reference: ";
        identify(*instance);

        delete instance;
    }

    std::cout << "\n=== Test 2: NULL Pointer Test ===" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Identify NULL pointer: ";
    identify(nullPtr);

    return 0;
}