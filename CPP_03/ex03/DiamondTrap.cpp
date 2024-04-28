#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("no_name_clap_name"){
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "no_name";
    ClapTrap::setHitPoints(FragTrap::getHitPoints());
    ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
    //----------------Printing-stats------------------//
    std::cout << "-------------Stats----------------" << std::endl;
    std::cout << "| ClapTrap::Name: " << this->getName() << " |" << std::endl;
    std::cout << "| this -> Name: " << this->getName() << "   |" << std::endl;
    std::cout << "| Hitpoints: " << this->getHitPoints() << "                 |" <<  std::endl;
    std::cout << "| Energy Points: " << this->getEnergyPoints() << "              |" << std::endl;
    std::cout << "| Attack Damage: " << this->getAttackDamage() << "              |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"){
    std::cout << "DiamondTrap name constructor called." << std::endl;
    this->name = name;
    ClapTrap::setHitPoints(FragTrap::getHitPoints());
    ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
    //----------------Printing-stats------------------//
    std::cout << "-------------Stats----------------" << std::endl;
    std::cout << "| ClapTrap::Name: " << this->getName() << " |" << std::endl;
    std::cout << "| this -> Name: " << this->getName() << "   |" << std::endl;
    std::cout << "| Hitpoints: " << FragTrap::getHitPoints() << "                 |" <<  std::endl;
    std::cout << "| Energy Points: " << this->getEnergyPoints() << "              |" << std::endl;
    std::cout << "| Attack Damage: " << this->getAttackDamage() << "              |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other){
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    //----------------Printing-stats------------------//
    std::cout << "-------------Stats----------------" << std::endl;
    std::cout << "| ClapTrap::Name: " << this->getName() << " |" << std::endl;
    std::cout << "| this -> Name: " << this->getName() << "   |" << std::endl;
    std::cout << "| Hitpoints: " << this->getHitPoints() << "                 |" <<  std::endl;
    std::cout << "| Energy Points: " << this->getEnergyPoints() << "              |" << std::endl;
    std::cout << "| Attack Damage: " << this->getAttackDamage() << "              |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}
DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other){
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other){
        ClapTrap::operator=(other);
    }
    return *this;
}
DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void    DiamondTrap::attack(std::string target){
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap's name: " << this->name << std::flush;
    std::cout << ", ClapTrap's name: " << ClapTrap::getName() << std::endl;
}