#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		
		void makeSound() const;
		void printIdeas() const;
		void addNewIdea(const std::string& newIdea);
};