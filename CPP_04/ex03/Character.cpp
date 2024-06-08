#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const string& name) : name(name){
    for(int i = 0; i < 4; i++){
        inventory[i] = NULL;
    }
}
Character::Character(const Character& other) : name(other.getName()) {
    for (int i = 0; i < 4; i++){
        inventory[i] = other.inventory[i];
    }
}
Character& Character::operator=(const Character& other){
    if(this != &other){
        name = other.getName();
        for (int i = 0; i < 4; i++){
            if (inventory[i])
                delete inventory[i];
            inventory[i] = other.inventory[i];
        }
    }
    return *this;
}
Character::~Character() {
    if (!inventory)
        return ;
    for (int i = 0; i < 4; i++){
        if (inventory[i])
            delete inventory[i];
    }
}
std::string const & Character::getName() const { return name; }
void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            return ;
        }
    }
    cout << "Inventory full" << endl;
}
void Character::unequip(int idx){
    if (idx < 0 || idx > 3)
        return ;
    if (inventory[idx])
        inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target){
    if (inventory[idx])
        inventory[idx]->use(target);
}