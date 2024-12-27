#include <iostream>
int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";

    // Указатель: можно переназначить
    std::string* stringPTR = &str1; // Указатель на str1
    stringPTR = &str2;             // Теперь указатель указывает на str2
    *stringPTR = "Changed by Pointer";

    std::cout << "str1: " << str1 << std::endl; // str1 остается "Hello"
    std::cout << "str2: " << str2 << std::endl; // str2 изменено

    // Ссылка: нельзя переназначить
    std::string& stringREF = str1; // Ссылка на str1
    // stringREF = &str2; // Ошибка компиляции: нельзя переназначить ссылку
    stringREF = "Changed by Reference";

    std::cout << "str1: " << str1 << std::endl; // str1 изменено через ссылку
    std::cout << "str2: " << str2 << std::endl; // str2 остается неизменным

    return 0;
}
