/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:19:01 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/28 21:38:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {}

HumanB::~HumanB() {}

void HumanB::attack( void ) {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType();
}

void HumanB::setWeapon(Weapon weapon) {
	*this->_weapon = weapon.getType();
}
