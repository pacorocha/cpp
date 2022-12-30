/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:19:22 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/29 19:56:23 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#pragma once

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB(void);

	void	attack(void);
	void	setWeapon(Weapon weapon);

private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif