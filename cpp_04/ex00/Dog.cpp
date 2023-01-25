#include "Dog.hpp"

// Constructors
Dog::Dog(void) : Animal()
{
	this->setType("Dog");
	this->setSound("barks");
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->setType(assign._type);
	this->setSound(assign._sound);
	return *this;
}
