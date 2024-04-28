#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
};
Cat::Cat(std::string type){
	std::cout << "Cat type constructor called" << std::endl;
	type = type;
}
Cat::Cat(Cat& other) : Animal(){
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.getType();
}
Cat& Cat::operator=(Cat& other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.getType();
	}
	return *this;
}
Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

void		Cat::makeSound(void) const{
	std::cout << "Miau Miau!" << std::endl;
}