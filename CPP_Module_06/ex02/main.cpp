#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Generate.hpp"
#include "Identify.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    A a;
    B b;
    C c;

    Base* basePtrA = &a;
    Base* basePtrB = &b;
    Base* basePtrC = &c;

    std::cout << "🚀 Explicitly created objects:" << std::endl;
    std::cout << "🌳 Identify with pointer (A): ";
    identify(basePtrA);
    std::cout << "🤖 Identify with reference (A): ";
    identify(*basePtrA);

    std::cout << "✨ Identify with pointer (B): ";
    identify(basePtrB);
    std::cout << "🔧 Identify with reference (B): ";
    identify(*basePtrB);

    std::cout << "🎉 Identify with pointer (C): ";
    identify(basePtrC);
    std::cout << "💻 Identify with reference (C): ";
    identify(*basePtrC);

    std::cout << "--------------------------" << std::endl;

    for (int i = 0; i < 5; ++i) {
        Base* ptr = generate();
        
        std::cout << "🛠️ Test " << i + 1 << ":" << std::endl;
        std::cout << "✅ Identify with pointer: ";
        identify(ptr);

        std::cout << "🚀 Identify with reference: ";
        identify(*ptr);

        delete ptr;

        std::cout << "--------------------------" << std::endl;
    }

    return 0;
}
