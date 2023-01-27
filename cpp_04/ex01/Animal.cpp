#include "Animal.hpp"

// Constructors
Animal::Animal(void) :
	type("Animal"),
	sound("makes sound")
{
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Animal::~Animal(void)
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}

// Operators
Animal & Animal::operator=(const Animal &assign)
{
	(void) assign;
	return *this;
}

// Methods

void Animal::setType(std::string type) {
	this->type = type;
}

void Animal::setSound(std::string sound) {
	this->sound = sound;
}

std::string	Animal::getType(void) const {
	return (this->type);
}

std::string	Animal::getSound(void) const {
	return (this->sound);
}

void	Animal::makeSound(void) const {
	std::cout << "The " + this->type + " " + this->sound << std::endl;
}
