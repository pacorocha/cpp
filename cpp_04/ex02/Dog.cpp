#include "Dog.hpp"

// Constructors
Dog::Dog(void)
{
	this->setType("Dog");
	this->setSound("barks");
	_brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal()
{
	type = copy.type;
	_brain = new Brain();
	*_brain = *(copy._brain);
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}

// Destructor
Dog::~Dog(void)
{
	delete _brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->setType(assign.type);
	this->setSound(assign.sound);
	return *this;
}

void	Dog::makeSound(void) {
	std::cout << "The " + this->type + " " + this->sound << std::endl;
}
