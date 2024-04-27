#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name(""),  hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage){
    std::cout << "Copy constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "Name constructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}
ClapTrap::~ClapTrap(){
    std::cout << "Destructor called" << std::endl;
}

bool    ClapTrap::checkStatus(void) const{
    bool status = true;
    if (this->energyPoints <= 0 || this->hitPoints <= 0){
        std::cout << "ClapTrap " << this->name << " has sadly powered down 😞." << std::endl;
        status = false;
    }
    return status;
}
void    ClapTrap::attack(const std::string& target){
    if (!this->checkStatus())
        return ;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}
void    ClapTrap::beRepaired(unsigned int amount){
    if (!this->checkStatus())
        return ;
    std::cout << "ClapTrap " << this->name << " has repaired " << amount << " hit points!" << std::endl;
    this->hitPoints += amount;
    this->energyPoints--;
}
void    ClapTrap::takeDamage(unsigned int amount){
    if (!this->checkStatus())
        return ;
    std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
    this->hitPoints -= amount;
}