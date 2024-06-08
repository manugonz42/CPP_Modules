#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string.h>
#include <iostream>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif