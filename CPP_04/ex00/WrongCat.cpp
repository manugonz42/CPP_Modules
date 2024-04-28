#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat Default constructor called" << std::endl;
	type = "WrongCat";
};
WrongCat::WrongCat(std::string type){
	std::cout << "WrongCat type constructor called" << std::endl;
	type = type;
}
WrongCat::WrongCat(WrongCat& other) : WrongAnimal(){
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = other.getType();
}
WrongCat& WrongCat::operator=(WrongCat& other){
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.getType();
	}
	return *this;
}
WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}
/*
void		WrongCat::makeSound(void) const{
	std::cout << "Miau Miau!" << std::endl;
}*/