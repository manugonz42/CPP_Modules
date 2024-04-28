#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string.h>
#include <iostream>

class	Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(Brain& other);
		~Brain();

		void addNewIdea(std::string newIdea);
		void printIdeas(void) const;
};

#endif