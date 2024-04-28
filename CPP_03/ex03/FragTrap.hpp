#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
    private:
        int     hitPoints;
        int     attackDamage;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void    highFivesGuys(void);
        void    setHitPoints(int newHitPoints);
        int     getHitPoints(void) const;
        void    setAttackDamage(int newAttackDamage);
        int     getAttackDamage(void) const;
};

#endif