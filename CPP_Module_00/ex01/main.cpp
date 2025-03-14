#include "PhoneBook.hpp"
#include <iostream>

// Little problem in ex01 - the "add" command accpet empty fields 
// and "search" command has problem when index is out of range.

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!\n";
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {  // Проверка состояния std::cin
            std::cout << "\nInput terminated. Exiting program.\n";
            break;  // Выход из цикла при EOF
        }

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
