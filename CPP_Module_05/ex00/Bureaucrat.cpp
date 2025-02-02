#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name_, int grade_) : name(name_), grade(grade_) {
    if (grade_ < 1)
        throw GradeTooHighException();
    if (grade_ > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "\033[1mGrade is too high!\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "\033[1mGrade is too low!\033[0m";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade \033[42m" << bureaucrat.getGrade() << "\033[0m.";
    return os;
}