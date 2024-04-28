#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap a;
    FragTrap b("pepo");

    std::cout << "Hola mundo" << std::endl;

    a.attack("pepo");
    a.beRepaired(5);
    a.takeDamage(5);
    
    b.attack("pepo");
    b.beRepaired(5);
    b.takeDamage(5);

    a.highFivesGuys();
    b.highFivesGuys();
    return 0;
}
