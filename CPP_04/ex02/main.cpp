#include "Dog.hpp"
#include "Cat.hpp"
#include <vector>

int main(void)
{
	Dog c1;
	Dog c2;
	c2 = c1;
	Dog c3(c1);

	//Dog*	d1 = new Dog();
	c1.addNewIdea("idea 1");
	c1.addNewIdea("idea 2");
	c2.addNewIdea("idea 3");
	c3.addNewIdea("idea 4");
	std::cout << "printing ideas " << std::endl;
	c1.printIdeas();
	std::cout << "printing 2 ideas " << std::endl;
	c2.printIdeas();

	return 0;
}
