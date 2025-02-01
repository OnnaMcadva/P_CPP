#pragma once

#include <iostream>
#include <string>

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void setName(std::string name);
    void announce() const;

private:
    std::string name;
    std::string color;

    std::string getColor() const;
};

Zombie* zombieHorde(int N, std::string name);
