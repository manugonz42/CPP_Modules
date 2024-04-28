#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <string.h>
#include <iostream>


class AAnimal{
	private:
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
	protected:
		AAnimal();
		std::string type;
	public:
		virtual ~AAnimal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif