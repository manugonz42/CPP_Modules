#pragma once
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter{
    private:
        string      name;
        AMateria*    inventory[4];
    public:
        Character(const string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};