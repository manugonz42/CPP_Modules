#pragma once

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const;
		void addNewIdea(const std::string& idea);
   		void printIdeas() const;
};