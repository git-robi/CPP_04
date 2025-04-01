#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << "=== Basic Materia and Character Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    
    src->learnMateria(new Ice());  
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    std::cout << "Created ice materia" << std::endl;
    
    me->equip(tmp);
    std::cout << "Equipped ice materia to slot 0" << std::endl;
    
    tmp = src->createMateria("cure");
    std::cout << "Created cure materia" << std::endl;
    me->equip(tmp);
    std::cout << "Equipped cure materia to slot 1" << std::endl;
    
    ICharacter* bob = new Character("bob");
    std::cout << "\nTesting use of equipped materias:" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    
    std::cout << "\n=== Testing Unlearned Materia ===" << std::endl;
    tmp = src->createMateria("fire"); // Should return NULL
    if (tmp == NULL)
        std::cout << "Successfully returned NULL for unknown materia type" << std::endl;
    
    std::cout << "\n=== Testing Full Inventory ===" << std::endl;
    // Fill inventory
    AMateria* stored[2]; // Store pointers for cleanup
    for (int i = 2; i < 4; i++) {
        tmp = src->createMateria("ice");
        std::cout << "Created additional ice materia" << std::endl;
        me->equip(tmp);
        std::cout << "Equipped ice materia to slot " << i << std::endl;
        stored[i-2] = tmp;
    }
    
    // Try to equip when full
    tmp = src->createMateria("cure");
    std::cout << "Attempting to equip materia when inventory is full..." << std::endl;
    me->equip(tmp); // Should fail
    delete tmp; // Clean up unequipped materia
    
    std::cout << "\n=== Testing Unequip ===" << std::endl;
    
    std::cout << "Unequipping materia from slot 0..." << std::endl;
    me->unequip(0); // Unequip ice
    std::cout << "Unequipping materia from slot 1..." << std::endl;
    me->unequip(1); // Unequip cure
    
    std::cout << "Testing use of unequipped slots:" << std::endl;
    me->use(0, *bob); // Should do nothing
    me->use(1, *bob); // Should do nothing
    
    std::cout << "\n=== Testing Character Copy ===" << std::endl;
    Character* john = new Character("john");
    tmp = src->createMateria("ice");
    std::cout << "Created new ice materia for john" << std::endl;
    john->equip(tmp);
    std::cout << "Equipped ice materia to john's slot 0" << std::endl;
    
    tmp = src->createMateria("cure");
    std::cout << "Created new cure materia for john" << std::endl;
    john->equip(tmp);
    std::cout << "Equipped cure materia to john's slot 1" << std::endl;
    
    std::cout << "\nCreating copy of john..." << std::endl;
    Character* john_copy = new Character(*john);
    
    std::cout << "Unequipping john's ice materia..." << std::endl;
    john->unequip(0);
    
    std::cout << "Testing if copy still has ice materia:" << std::endl;
    john_copy->use(0, *bob); // Should still work
    
    delete john_copy;
    delete john;
    delete bob;
    delete me;
    delete src;
    
    return 0;
}