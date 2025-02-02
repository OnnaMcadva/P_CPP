#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("\033[33mJohn\033[0m", 1);
        Bureaucrat alice("\033[36mAlice\033[0m", 150);

        Form TaxForm("Tax Form", 1, 1);
        Form LeaveForm("Leave Form", 150, 150);

        std::cout << TaxForm << std::endl;
        std::cout << LeaveForm << std::endl;

        john.signForm(TaxForm);
        alice.signForm(LeaveForm);

        alice.signForm(TaxForm);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}