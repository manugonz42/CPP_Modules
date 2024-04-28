#include "Diamondtrap.hpp"

int main(void)
{

    DiamondTrap b("pepo");

    std::cout << "Hola mundo" << std::endl;
    
    b.attack("pepo");
    b.beRepaired(5);
    b.takeDamage(5);

    b.highFivesGuys();

    b.whoAmI();
    return 0;
}
