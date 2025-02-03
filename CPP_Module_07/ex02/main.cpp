#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "📚 Creating array of " << MAX_VAL << " integers." << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Array📚 initialized with random values." << std::endl;

    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Temporary arrays created using copy constructor and assignment operator." << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror;
            return 1;
        }
    }
    std::cout << "Values in both arrays are the same." << std::endl;

    std::cout << "\n\033[3mAccessing valid indexes:\033[0m" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    try
    {
        std::cout << "\nAttempting to access index -2." << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[42mException:\033[0m " << e.what() << '\n';
    }
    try
    {
        std::cout << "Attempting to access index " << MAX_VAL << "." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[42mException:\033[0m " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "Array📚 values modified with new random values." << std::endl;
    delete[] mirror;
    return 0;
}
