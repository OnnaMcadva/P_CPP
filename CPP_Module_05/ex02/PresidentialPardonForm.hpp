#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    virtual void execute(const Bureaucrat& executor) const;
};
