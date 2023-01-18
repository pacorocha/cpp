#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() {
	this->_name.assign("Anonymous ScavTrap");
	this->_model.assign("ScavTrap");
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m " + this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->_name = name;
	this->_model.assign("ScavTrap");
	std::cout << "\e[0;33mDefault String Constructor called of ScavTrap\e[0m " + this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap() {
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" + this->_name << std::endl;
	*this = copy;
}


// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign) {
	(void) assign;
	return *this;
}

void	ScavTrap::guardGate(void) {
	std::cout << this->_name + " is now in Gate Keeper mode." << std::endl;
}

