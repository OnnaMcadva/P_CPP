#include <iostream>

#define DEF_COLOR "\033[0;39m"
#define RED "\033[0;91m"
#define ORANGE "\033[38;5;214m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;92m"
#define BLUE "\033[0;94m"
#define INDIGO "\033[38;5;54m"
#define VIOLET "\033[38;5;129m"

int main() {

    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;

    std::string& stringREF = str;

    std::cout << RED "Memory address of the string variable: " DEF_COLOR << &str << std::endl;
    std::cout << ORANGE "Memory address held by stringPTR: " DEF_COLOR << stringPTR << std::endl;
    std::cout << YELLOW "Memory address held by stringREF: " DEF_COLOR << &stringREF << std::endl;

    std::cout << GREEN "Value of the string variable: " DEF_COLOR << str << std::endl;
    std::cout << BLUE "Value pointed to by stringPTR: " DEF_COLOR << *stringPTR << std::endl;
    std::cout << INDIGO "Value pointed to by stringREF: " DEF_COLOR << stringREF << std::endl;

    return 0;
}

/*Указатель гибче (может менять объект, на который указывает).
Ссылка проще в использовании, но жестко привязана к одному объекту.
Если вы понимаете, что объект, с которым будете работать, не изменится 
(например, это всегда будет str), то лучше использовать ссылку.
Если требуется гибкость в смене объекта, используйте указатель.*/
