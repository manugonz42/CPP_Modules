#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string.h>
#include <iostream>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal& other);
		Animal& operator=(Animal& other);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif