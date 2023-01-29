#include "Cat.hpp"

// Constructors
Cat::Cat(void) : Animal()
{
	this->setType("Cat");
	this->setSound("meows");
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Cat::~Cat(void)
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->setType(assign.type);
	this->setSound(assign.sound);
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "The " + this->type + " " + this->sound + " as a cat."<< std::endl;
}
