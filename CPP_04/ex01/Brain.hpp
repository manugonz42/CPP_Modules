#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string.h>
#include <iostream>

class	Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain& other);
		Brain& operator=(Brain& other);
		~Brain();
};

#endif