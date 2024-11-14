/*
#include "PhoneBook.hpp"
#include <limits> // Добавляем эту библиотеку для std::numeric_limits

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    if (contactCount < 8) {
        contacts[contactCount] = newContact;
        ++contactCount;
    } else {
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
    std::cout << "Contact added successfully!\n";
}

void PhoneBook::searchContact() const {
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    for (int i = 0; i < contactCount; ++i) {
        std::cout << "|" << std::setw(10) << i + 1
                  << "|" << std::setw(10) << truncate(contacts[i].getFirstName(), 10)
                  << "|" << std::setw(10) << truncate(contacts[i].getLastName(), 10)
                  << "|" << std::setw(10) << truncate(contacts[i].getNickname(), 10)
                  << "|\n";
    }
    
    int index;
    std::cout << "Enter contact index to view details: ";
    std::cin >> index;
    if (std::cin.fail() || index < 1 || index > contactCount) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index!\n";
    } else {
        displayContactInfo(index - 1);
    }
}

void PhoneBook::displayContactInfo(int index) const {
    std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
}

std::string PhoneBook::truncate(const std::string &str, size_t width) const {
    return str.length() > width ? str.substr(0, width - 1) + "." : str;
}
*/

#include "PhoneBook.hpp"
#include <limits>

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << GREEN << "Enter first name: " << RESET;
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << GREEN << "Enter last name: " << RESET;
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << GREEN << "Enter nickname: " << RESET;
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << GREEN << "Enter phone number: " << RESET;
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << GREEN << "Enter darkest secret: " << RESET;
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    if (contactCount < 8) {
        contacts[contactCount] = newContact;
        ++contactCount;
    } else {
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
    std::cout << YELLOW << "Contact added successfully!\n" << RESET;
}

void PhoneBook::searchContact() const {
    std::cout << MAGENTA << "|     Index|First Name| Last Name|  Nickname|\n" << RESET;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << "|" << std::setw(10) << i + 1
                  << "|" << std::setw(10) << truncate(contacts[i].getFirstName(), 10)
                  << "|" << std::setw(10) << truncate(contacts[i].getLastName(), 10)
                  << "|" << std::setw(10) << truncate(contacts[i].getNickname(), 10)
                  << "|\n";
    }
    
    int index;
    std::cout << BLUE << "Enter contact index to view details: " << RESET;
    std::cin >> index;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (std::cin.fail() || index < 1 || index > contactCount) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Invalid index!\n" << RESET;
    } else {
        displayContactInfo(index - 1);
    }
}

void PhoneBook::displayContactInfo(int index) const {
    std::cout << YELLOW << "First Name: " << contacts[index].getFirstName() << RESET << "\n";
    std::cout << YELLOW << "Last Name: " << contacts[index].getLastName() << RESET << "\n";
    std::cout << YELLOW << "Nickname: " << contacts[index].getNickname() << RESET << "\n";
    std::cout << YELLOW << "Phone Number: " << contacts[index].getPhoneNumber() << RESET << "\n";
    std::cout << YELLOW << "Darkest Secret: " << contacts[index].getDarkestSecret() << RESET << "\n";
}

std::string PhoneBook::truncate(const std::string &str, size_t width) const {
    return str.length() > width ? str.substr(0, width - 1) + "." : str;
}
