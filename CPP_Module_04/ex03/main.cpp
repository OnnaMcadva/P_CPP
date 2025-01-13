// #include "MateriaSource.hpp"
// #include "Character.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"

// int main() {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
    
//     ICharacter* me = new Character("me");

//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
    
//     ICharacter* bob = new Character("bob");
    
//     me->use(0, *bob);
//     me->use(1, *bob);
    
//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp" // Подключаем новый класс

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Fire()); // Учим новый тип Materia

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire"); // Создаём огненную Materia
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob); // Ice
    me->use(1, *bob); // Cure
    me->use(2, *bob); // Fire

    delete bob;
    delete me;
    delete src;

    return 0;
}
