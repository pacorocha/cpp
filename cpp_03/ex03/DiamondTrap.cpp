#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap() :
	ClapTrap(),
	ScavTrap(),
	FragTrap(),
	_name("AnonymousDiamondTrap") {
	this->setHitPoints(FragTrap::_hit_points);
	this->setEnergyPoints(ScavTrap::_energy_points);
	this->setAttackDamage(FragTrap::_attack_damage);
	this->setModel("DiamondTrap");
	this->setName(ClapTrap::getName() + "_clap_name");
	std::cout << "\e[0;33mDefault Constructor called of " + this->_model + "\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) :
	ClapTrap(),
	ScavTrap(),
	FragTrap()
{
	std::cout << "\e[0;33mCopy Constructor called of " + this->_model + "\e[0m" << std::endl;
	*this = copy;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name),
	ScavTrap(name),
	FragTrap(name),
	_name(name) {
	this->setHitPoints(FragTrap::_hit_points);
	this->setEnergyPoints(ScavTrap::_energy_points);
	this->setAttackDamage(FragTrap::_attack_damage);
	this->setModel("DiamondTrap");
	this->setName(ClapTrap::getName() + "_clap_name");
	std::cout << "\e[0;33mDefault String Constructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of " + this->_model + " \e[0m" + this->_name << std::endl;
}

// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &copy)
{
	this->setName(copy.getName());
	this->setHitPoints(copy.getHitPoints());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setAttackDamage(copy.getAttackDamage());
	this->setModel(copy.getModel());
	this->_name = copy.get_Name();
	return *this;
}

// Methods
std::string	DiamondTrap::get_Name(void) const {
	return this->_name;
}

void		DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "I'm " + this->_model + " " + this->_name << std::endl;
  std::cout << " and ClapTrap: " + ClapTrap::getName() << std::endl;
}
