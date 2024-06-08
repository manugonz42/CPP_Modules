#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default constructor called" << std::endl;
};
Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat type constructor called" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}
Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}
void		Cat::makeSound(void) const{
	std::cout << "Miau Miau!" << std::endl;
}