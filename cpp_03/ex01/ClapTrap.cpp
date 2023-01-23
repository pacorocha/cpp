/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:16 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/23 19:30:46 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(void) :
	_name("Anonymous"),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0),
	_model("ClapTrap") {
	std::cout << "\e[0;32mDefault Constructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string const& name) :
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0),
	_model("ClapTrap") {
	std::cout << "\e[0;32mDefault String Constructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "\e[0;32mCopy Constructor called of " + this->_model + "\e[0m " + copy._name << std::endl;
	*this = copy;
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "\e[0;31mDestructor called of " + this->_model + "\e[0m " + this->_name << std::endl;
}

// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &source) {
	std::cout << "\e[0;32mCopy assignment operator called of " + this->_model + "\e[0m " + source._name << std::endl;
	this->_name = source.getName();
	this->_model = source.getModel();
	this->_hit_points = source.getHitPoints();
	this->_energy_points = source.getEnergyPoints();
	this->_attack_damage = source.getAttackDamage();

	return (*this);
}

// Methods
void ClapTrap::setName(std::string const &name) {
	this->_name = name;
}

void ClapTrap::setHitPoints(int amount) {
	this->_hit_points = amount;
}

void ClapTrap::setEnergyPoints(int amount) {
	this->_energy_points = amount;
}

void ClapTrap::setAttackDamage(int amount) {
	this->_attack_damage = amount;
}

void ClapTrap::setModel(std::string const &model) {
	this->_model = model;
}

int ClapTrap::getAttackDamage(void) const {
	return (this->_attack_damage);
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

std::string ClapTrap::getModel(void) const {
	return (this->_model);
}

int ClapTrap::getEnergyPoints(void) const {
	return (this->_energy_points);
}

int ClapTrap::getHitPoints(void) const {
	return (this->_hit_points);
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energy_points > 0 && this->_hit_points > 0) {
		std::cout << "\e[0;35m" << this->_model << " " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage.\e[0m" << std::endl;
		this->_energy_points--;
	} else {
		std::cout << "\e[0;36m" + this->_model + " " + this->_name + " is unable to attack.\e[0m" << std::endl;
	}
}

void ClapTrap::takeDamage(int amount) {
	std::cout << "\e[0;101m" << this->_model << " " << this->_name << " takes " << amount << " points of damage.\e[0m" << std::endl;
	this->_hit_points -= amount;
	std::cout << "\e[0;101m" << this->_model << " " << this->_name << " now has " << this->_hit_points << " hit points.\e[0m" << std::endl;
}

void ClapTrap::beRepaired(int amount) {
	if (this->_energy_points > 0 && this->_hit_points > 0) {
		std::cout << this->_model << this->_name << " repairs itself and gets " << amount << " health points." << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	} else {
		std::cout << "\e[0;107m" << this->_model << " " << this->_name << " is unable to repair itself.\e[0m" << std::endl;
	}
}
