#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <vector>

int main(void)
{
	int n;
	std::vector <Animal*> animals;
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	for (n = 0; n < 6; n++){
		if (n % 2 == 0)
			animals.push_back(new Dog);
		else
			animals.push_back(new Cat);
	}
	std::cout  << std::endl << "Bucle tests:" <<std::endl;
	for (n = 0; n < 6; n++){
		std::cout << animals[n]->getType() << " says ";
		animals[n]->makeSound();
	}
	for (n = 0; n < 6; n++){
		delete animals[n];
	}
	delete j;
	delete i;
	delete meta;
	
	return 0;
}
