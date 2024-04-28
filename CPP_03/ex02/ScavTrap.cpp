#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap name constructor called." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap&    ScavTrap::operator=(const ScavTrap& other){
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other){
        ClapTrap::operator=(other);
    }
    return *this;
}
ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::attack(std::string target){
    if (!this->checkStatus())
        return ;
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
}
void    ScavTrap::guardGate(void){
    if (!this->checkStatus())
        return ;
    std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode." << std::endl;
}