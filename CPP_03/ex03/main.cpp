#include "DiamondTrap.hpp"

int main(void)
{

    DiamondTrap b("pepo");

    b.attack("pepo");
    b.beRepaired(5);
    b.takeDamage(5);

    b.highFivesGuys();

    b.whoAmI();
    return 0;
}
