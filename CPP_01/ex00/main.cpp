#include "Zombie.hpp"

Zombie *newZombie(std::string name);

void	randomChump(std::string name);

int main(void){
	std::string name;

	std::cout << "Creating heap Zombie, name it: " << std::endl;
	std::getline(std::cin, name);
	Zombie *zombie = newZombie(name);
	zombie->announce();
	delete zombie;

	std::cout << "Creating stack Zombie, name it: " << std::endl;
	std::getline(std::cin, name);
	randomChump(name);

	std::cout << "Calling randomChump with no name" << std::endl;
	randomChump("");
	
	return 0;
}
