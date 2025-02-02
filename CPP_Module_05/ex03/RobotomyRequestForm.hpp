#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string target;

public:
    RobotomyRequestForm(const std::string& target_param);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    virtual void execute(const Bureaucrat& executor) const;
};
