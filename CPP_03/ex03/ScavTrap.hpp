#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    private:
        int     energyPoints;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        void    attack(std::string target);
        void    guardGate();
        void    setEnergyPoints(int newEnergyPoints);
        int     getEnergyPoints(void) const;


};

#endif