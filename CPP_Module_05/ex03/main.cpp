#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
    unknown = someRandomIntern.makeForm("unknown form", "Target");

    if (unknown == NULL) {
        std::cout << "Unknown form was not created." << std::endl;
    }

    delete rrf;
    delete scf;
    delete ppf;

    return 0;
}