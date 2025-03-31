#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* slots[4];
        AMateria* floor[100];

    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(Character const &other);
        Character& operator=(Character const &other);

        std::string const & getName() const;

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
