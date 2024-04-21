#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

Zombie *newZombie(std::string name);

void	randomChump(std::string name);

int main(void){
	std::string name;
	int			N;
	std::cout << "Creating horde, enter the size: " << std::endl;
	std::cin >> N;
	std::cin.ignore();
	std::cout << "name the zombies: " << std::endl;
	std::getline(std::cin, name);
	Zombie *zombies = zombieHorde(N, name);
	for (int i = 0; i < N; ++i) {
		zombies[i].announce();
	}
	delete[] zombies;
	
	return 0;
}
