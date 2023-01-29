#include "Dog.hpp"

// Constructors
Dog::Dog(void) : Animal()
{
	this->setType("Dog");
	this->setSound("barks");
	brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
	type = copy.type;
	brain = new Brain();
	*brain = *(copy.brain);
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}

// Destructor
Dog::~Dog(void)
{
	delete brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->setType(assign.type);
	this->setSound(assign.sound);
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "The " + this->type + " " + this->sound + " as a dog."<< std::endl;
}
