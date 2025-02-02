#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("\033[33mJohn\033[0m", 5);

        ShrubberyCreationForm scf("home");
        RobotomyRequestForm rrf("\033[35mrobot\033[0m");
        PresidentialPardonForm ppf("\033[36mAlice\033[0m");

        john.signForm(scf);
        john.executeForm(scf);

        john.signForm(rrf);
        john.executeForm(rrf);

        john.signForm(ppf);
        john.executeForm(ppf);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
