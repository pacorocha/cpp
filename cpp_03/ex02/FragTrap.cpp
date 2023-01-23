#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() {
	this->_name.assign("Anonymous FragTrap");
	this->_model.assign("FragTrap");
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m " + this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->_name = name;
	this->_model.assign("FragTrap");
	std::cout << "\e[0;33mDefault String Constructor called of FragTrap\e[0m " + this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ScavTrap() {
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" + this->_name << std::endl;
	*this = copy;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign) {
	(void) assign;
	return *this;
}

void highFivesGuys(void) {
	std::cout << this->_name + " says \"Gimme five, you guys!\"." << std::endl;
}
