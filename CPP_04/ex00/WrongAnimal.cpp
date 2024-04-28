#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("NONE") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
};
WrongAnimal::WrongAnimal(std::string type) : type(type){
	std::cout << "WrongAnimal type constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal& other) : type(other.getType()){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(WrongAnimal& other){
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.getType();
	}
	return *this;
}
WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return this->type;
}
void		WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal sound" << std::endl;
}