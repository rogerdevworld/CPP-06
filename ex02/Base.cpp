#include <iostream>
#include <cstdlib>
#include <exception>
#include "Base.hpp"

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

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}