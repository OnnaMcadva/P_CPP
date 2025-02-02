#include "Form.hpp"

Form::Form(const std::string& name_, int gradeToSign, int gradeToExecute)
    : name(name_), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

std::string Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeRequiredToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << ", Status: " << (form.getIsSigned() ? "Signed" : "Unsigned")
       << ", Grade required to sign: " << form.getGradeRequiredToSign()
       << ", Grade required to execute: " << form.getGradeRequiredToExecute();
    return os;
}