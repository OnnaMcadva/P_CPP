#pragma once

#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat(const std::string& name_param, int grade_param);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm& form);
    void executeForm(const AForm& form);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};