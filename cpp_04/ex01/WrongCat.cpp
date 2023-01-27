#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
	*this = copy;
}

// Destructor
WrongCat::~WrongCat(void)
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}

// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	this->type = assign.type;
	return *this;
}
