#pragma once

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat& other);
		Cat& operator=(Cat& other);
		~Cat();

		void makeSound() const;
};