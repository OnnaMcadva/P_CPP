#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "✨ Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "🎉 Stack size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "✨ Stack elements (using forward iterator):" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "✨ Copied stack elements (using std::stack):" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    std::cout << "✨ Stack elements (using reverse iterator):" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}
