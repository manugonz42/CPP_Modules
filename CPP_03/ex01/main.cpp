#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a;
    ScavTrap b("pepo");

    std::cout << "Hola mundo" << std::endl;

    a.attack("pepo");
    a.beRepaired(5);
    a.takeDamage(5);
    
    b.attack("pepo");
    b.beRepaired(5);
    b.takeDamage(5);


    return 0;
}
