#pragma once

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		
		void makeSound() const;
};