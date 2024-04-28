#include "AAnimal.hpp"

AAnimal::AAnimal() : type("NONE") {
	std::cout << "AAnimal Default constructor called" << std::endl;
};
AAnimal::AAnimal(std::string type) : type(type){
	std::cout << "AAnimal type constructor called" << std::endl;
}
AAnimal::AAnimal(const AAnimal& other) : type(other.getType()){
	std::cout << "AAnimal copy constructor called" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal& other){
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.getType();
	}
	return *this;
}
AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const{
	return this->type;
}
void		AAnimal::makeSound(void) const{
	std::cout << "AAnimal base sound" << std::endl;
}