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
    bool    check;
    for (int i = 0; i < 4; i++){
        check = false;
        if (inventory[i]){
            if (i > 0){
                for (int j = 0; j < i; j++)
                    if (inventory[i] == inventory[j]){
                        check = true;
                        break ;
                    }
            }
            if (check)
                continue;
            delete inventory[i];
        }
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
        cout << "No slot " << idx << endl;
    else if (inventory[idx])
        inventory[idx] = NULL;
    else
        cout << "Nothing equiped in slot " << idx << endl;
}
void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3)
        cout << "No slot " << idx << endl;
    else if (inventory[idx])
        inventory[idx]->use(target);
    else
        cout << "Nothing equiped in slot " << idx << endl;
}