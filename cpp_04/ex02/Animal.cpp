#include "Animal.hpp"

// Constructors
AAnimal::AAnimal(void) :
	type("AAnimal"),
	sound("makes sound")
{
	std::cout << "\e[0;33mDefault Constructor called of AAnimal\e[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of AAnimal\e[0m" << std::endl;
	*this = copy;
}

// Destructor
AAnimal::~AAnimal(void)
{
	std::cout << "\e[0;31mDestructor called of AAnimal\e[0m" << std::endl;
}

// Operators
AAnimal & AAnimal::operator=(const AAnimal &assign)
{
	(void) assign;
	return *this;
}

// Methods

void AAnimal::setType(std::string type) {
	this->type = type;
}

void AAnimal::setSound(std::string sound) {
	this->sound = sound;
}

std::string	AAnimal::getType(void) const {
	return (this->type);
}

std::string	AAnimal::getSound(void) const {
	return (this->sound);
}

void	AAnimal::makeSound(void) {
	std::cout << "The " + this->type + " " + this->sound << std::endl;
}
