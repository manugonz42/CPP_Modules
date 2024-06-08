#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
};
Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog type constructor called" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other){
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}
Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void		Dog::makeSound(void) const{
	std::cout << "Bof Bof!" << std::endl;
}