#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : brain(new Brain()){
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
};
Cat::Cat(std::string type) : brain(new Brain()){
	std::cout << "Cat type constructor called" << std::endl;
	type = type;
}
Cat::Cat(const Cat& other) : AAnimal(), brain(new Brain(*other.brain)){
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
}
Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other){
		delete brain;
		brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return *this;
}
Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void		Cat::makeSound(void) const{
	std::cout << "Miau Miau!" << std::endl;
}
void Cat::addNewIdea(const std::string& idea) {
    brain->addNewIdea(idea);
}

void Cat::printIdeas() const {
    brain->printIdeas();
}