#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook {
public:
    PhoneBook();
    void addContact();
    void searchContact() const;

private:
    Contact contacts[8];
    int contactCount;
    int oldestContactIndex;

    void displayContactInfo(int index) const;
    std::string truncate(const std::string &str, size_t width) const;
};

#endif
