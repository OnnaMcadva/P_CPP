#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target_param)
    : AForm("Shrubbery Creation Form", 145, 137), target(target_param) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());
    std::string tree = 
        "  ^  \n"
        " ^^^ \n"
        "^^^^^\n"
        "  |  \n";
    file << tree;
    file.close();
    std::cout << tree;
}
