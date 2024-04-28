#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++){
		ideas[i] = "No idea";
	}
};
Brain::Brain(Brain& other){
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++){
		ideas[i] = other.ideas[i];
	}
}
Brain& Brain::operator=(Brain& other){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other){
		for (int i = 0; i < 100; i++){
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}