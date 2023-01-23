#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap() {
	this->setName("Anonymous");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setModel("FragTrap");
	std::cout << "Default Constructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setModel("FragTrap");
	std::cout << "Default Constructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap() {
	std::cout << "Copy Constructor called of " + this->_model + "\e[0m" + this->_name << std::endl;
	*this = copy;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "\e[0;31mDestructor called of " + this->_model + "\e[0m" << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(const FragTrap &copy) {
	this->setName(copy.getName());
	this->setHitPoints(copy.getHitPoints());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setAttackDamage(copy.getAttackDamage());
	this->setModel(copy.getModel());
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << this->_model + " " + this->_name + " says \"Gimme five, you guys!\"." << std::endl;
}
