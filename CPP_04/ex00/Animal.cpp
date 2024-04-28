#include "Animal.hpp"

Animal::Animal() : type("NONE") {
	std::cout << "Animal Default constructor called" << std::endl;
};
Animal::Animal(std::string type) : type(type){
	std::cout << "Animal type constructor called" << std::endl;
}
Animal::Animal(Animal& other) : type(other.getType()){
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(Animal& other){
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.getType();
	}
	return *this;
}
Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const{
	return this->type;
}
void		Animal::makeSound(void) const{
	std::cout << "Animal base sound" << std::endl;
}