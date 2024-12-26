#include "Zombie.hpp"
#include <new> 
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = reinterpret_cast<Zombie*>(operator new[](N * sizeof(Zombie)));
    for (int i = 0; i < N; ++i) {
        std::ostringstream oss;
        oss << name << " #" << i + 1;
        new (&horde[i]) Zombie(oss.str());
    }
    return horde;
}
