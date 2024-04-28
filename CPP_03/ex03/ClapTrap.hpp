#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string.h>

class ClapTrap{
    private:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        bool checkStatus(void) const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string    getName(void) const;
        int            getHitPoints(void) const;
        int            getEnergyPoints(void) const;
        int            getAttackDamage(void) const;

        void    setHitPoints(int newHitPoints);
        void    setEnergyPoints(int newEnergyPoints);
        void    setAttackDamage(int newAttackDamage);
};
#endif