#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"){
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "Default";
    this->setHitpoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(FragTrap::getAttackDamage());
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"){
    std::cout << "DiamondTrap name constructor called." << std::endl;
    this->name = name;
    ClapTrap::setHitpoints(FragTrap::getHitPoints());
    ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other){
    std::cout << "DiamondTrap copy constructor called" << std::endl;
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
    std::cout << "DiamondTrap's name: " << this->name << std::endl;
    std::cout << "ClapTrap's name: " << ClapTrap::getName() << std::endl;
}