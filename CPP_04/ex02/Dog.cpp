#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : brain(new Brain()){
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
};
Dog::Dog(std::string type) : brain(new Brain()){
	std::cout << "Dog type constructor called" << std::endl;
	type = type;
}
Dog::Dog(const Dog& other) : AAnimal(), brain(new Brain(*other.brain)){
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
}
Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other){
		delete brain;
		brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return *this;
}
Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void		Dog::makeSound(void) const{
	std::cout << "Miau Miau!" << std::endl;
}
void Dog::addNewIdea(const std::string& idea) {
    brain->addNewIdea(idea);
}
void Dog::printIdeas() const {
    brain->printIdeas();
}