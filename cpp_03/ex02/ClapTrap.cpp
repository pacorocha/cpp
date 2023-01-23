/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:16 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/18 22:46:26 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"



// Constructors
ClapTrap::ClapTrap(void) :
	_name("Anonymous"),
	_model("ClapTrap"),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0) {
	std::cout << "\e[0;32mDefault Constructor called of ClapTrap\e[0m " + this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_model("ClapTrap") {
	std::cout << "\e[0;32mDefault String Constructor called of ClapTrap\e[0m " + this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "\e[0;32mCopy Constructor called of ClapTrap\e[0m " + copy._name << std::endl;
	*this = copy;
}


// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m " + this->_name << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign) {
	this->_name = assign._name;
	this->_model = assign._model;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energy_points > 0 && this->_hit_points > 0) {
		std::cout << "\e[0;35m" << this->_model << " " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage.\e[0m" << std::endl;
		this->_energy_points--;
	} else {
		std::cout << "\e[0;36m" + this->_model + " " + this->_name + " is unable to attack.\e[0m" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "\e[0;101m" << this->_model << " " << this->_name << " takes " << amount << " points of damage.\e[0m" << std::endl;
	this->_hit_points -= amount;
	std::cout << "\e[0;101m" << this->_model << " " << this->_name << " now has " << this->_hit_points << " points of damage.\e[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points > 0 && this->_hit_points > 0) {
		std::cout << this->_model << this->_name << " repairs itself and gets " << amount << " health points." << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	} else {
		std::cout << "\e[0;107m" << this->_model << " " << this->_name << " is unable to repair itself.\e[0m" << std::endl;
	}
}

int ClapTrap::getAttackDamage(void) {
	return (this->_attack_damage);
}

std::string ClapTrap::getName(void) {
	return (this->_name);
}
