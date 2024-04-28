#pragma once

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat& other);
		Cat& operator=(Cat& other);
		~Cat();

		void makeSound() const;
};