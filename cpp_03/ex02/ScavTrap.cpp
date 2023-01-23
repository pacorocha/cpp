#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(void) : ClapTrap() {
	this->setName("Anonymous");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setModel("ScavTrap");
	std::cout << "\e[0;32mDefault Constructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setModel("ScavTrap");
	std::cout << "\e[0;33mDefault String Constructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap() {
	std::cout << "\e[0;33mCopy Constructor called of " + this->_model + "\e[0m" + this->_name << std::endl;
	*this = copy;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "\e[0;31mDestructor called of " + this->_model + "\e[0m" << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &copy) {
	this->setName(copy.getName());
	this->setHitPoints(copy.getHitPoints());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setAttackDamage(copy.getAttackDamage());
	this->setModel(copy.getModel());
	return *this;
}

// Methods
void	ScavTrap::guardGate(void) {
	if (this->_energy_points > 0 && this->_hit_points > 0) {
		std::cout << this->_model + " " + this->_name + " is now in Gate Keeper mode." << std::endl;
		this->_energy_points--;
	} else {
		std::cout << "\e[0;107m" << this->_model + " " + this->_name + " is unable to enter Gate Keeper mode.\e[0m" << std::endl;
	}

}

