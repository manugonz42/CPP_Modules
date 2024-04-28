#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(WrongCat& other);
		WrongCat& operator=(WrongCat& other);
		~WrongCat();

		//void makeSound() const;
};