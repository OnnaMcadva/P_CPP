#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name_param) : name(name_param) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
    //std::cout << name << " has been created" << std::endl;
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = NULL;
        }
    }
    std::cout << "Character copied" << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        cleanInventory();
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            } else {
                inventory[i] = NULL;
            }
        }
    }
    std::cout << "Character assigned" << std::endl;
    return *this;
}

Character::~Character() {
    cleanInventory();
    //std::cout << name << " has been destroyed" << std::endl;
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}

void Character::cleanInventory() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
        inventory[i] = NULL;
    }
}
