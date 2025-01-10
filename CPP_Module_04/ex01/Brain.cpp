#include "Brain.hpp"

Brain::Brain() {
    std::cout << "\033[34mBrain created\033[0m" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copied" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain assigned" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "\033[31mBrain destroyed\033[0m" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}
