#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name_param, int gradeToSign_param, int gradeToExecute_param)
    : name(name_param), isSigned(false), gradeToSign(gradeToSign_param), gradeToExecute(gradeToExecute_param) {
    if (gradeToSign_param < 1 || gradeToExecute_param < 1)
        throw GradeTooHighException();
    if (gradeToSign_param > 150 || gradeToExecute_param > 150)
        throw GradeTooLowException();
}


AForm::~AForm() {}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}