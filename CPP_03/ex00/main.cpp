#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b("pepo");

    std::cout << "Hola mundo" << std::endl;

    a.attack("pepo");
    a.beRepaired(5);
    a.takeDamage(5);
    
    b.attack("pepo");
    b.beRepaired(5);
    b.takeDamage(5);
    for (int i = 0 ; i < 12; i++)
        b.attack("loli");

    return 0;
}
