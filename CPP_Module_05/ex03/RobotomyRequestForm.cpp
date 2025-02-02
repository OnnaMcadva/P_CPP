#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target_param)
    : AForm("Robotomy Request Form", 72, 45), target(target_param) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "\033[1;32mDrilling noises...\033[0m\n";
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully.\n";
    else
        std::cout << "Robotomy failed.\n";
}
