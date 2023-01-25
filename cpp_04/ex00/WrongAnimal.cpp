#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
	*this = copy;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}

// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return *this;
}

// Methods
std::string	WrongAnimal::getType() const {
	return (this->type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "The " + this->type + " makes sound." << std::endl;
}
