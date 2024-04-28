#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog& other);
		Dog& operator=(Dog& other);
		~Dog();
		
		void makeSound() const;
};