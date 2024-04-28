#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
};
Dog::Dog(std::string type){
	std::cout << "Dog type constructor called" << std::endl;
	type = type;
}
Dog::Dog(Dog& other) : Animal(){
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.getType();
}
Dog& Dog::operator=(Dog& other){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.getType();
	}
	return *this;
}
Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void		Dog::makeSound(void) const{
	std::cout << "Bof Bof!" << std::endl;
}