#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int choice = std::rand() % 3;
    if (choice == 0) {
        std::cout << "[Generated: A]" << std::endl;
        return new A();
    } else if (choice == 1) {
        std::cout << "[Generated: B]" << std::endl;
        return new B();
    } else {
        std::cout << "[Generated: C]" << std::endl;
        return new C();
    }
}

// Identificación vía puntero
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Pointer is NULL" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identificación vía referencia (Prohibido usar punteros dentro)
void identify(Base& p) {
    try {
        A& aux = dynamic_cast<A&>(p);
        (void)aux;
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception&) {}

    try {
        B& aux = dynamic_cast<B&>(p);
        (void)aux;
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception&) {}

    try {
        C& aux = dynamic_cast<C&>(p);
        (void)aux;
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}

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