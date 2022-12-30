/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:18:29 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/29 19:55:23 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
	_name(name),
	_weapon(weapon) {
}

HumanA::~HumanA(void) {}

void HumanA::attack(void) {
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType();
}
