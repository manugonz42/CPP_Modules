#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++){
		ideas[i] = "No idea";
	}
};
Brain::Brain(const Brain& other){
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
void	Brain::addNewIdea(std::string newIdea){
	for (long long unsigned int i = 0; i < sizeof(ideas) / sizeof(ideas[0]); ++i) {
		if (ideas[i] == "No idea"){
        	ideas[i] = newIdea;
			break ;
		}
    }
}
void	Brain::printIdeas(void) const{
	for (long long unsigned int i = 0; i < sizeof(ideas) / sizeof(ideas[0]); ++i) {
		if (ideas[i] != "No idea")
        	std::cout << ideas[i] << std::endl;
    }
}