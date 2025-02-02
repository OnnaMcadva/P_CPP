#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& m_formName, const std::string& m_target) {
    std::string m_formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formCreators[])(const std::string&) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (size_t i = 0; i < 3; ++i) {
        if (m_formName == m_formNames[i]) {
            std::cout << "Intern creates " << m_formName << std::endl;
            return (this->*formCreators[i])(m_target);
        }
    }

    std::cout << "Intern cannot create " << m_formName << " form. Form name is unknown." << std::endl;
    return NULL;
}