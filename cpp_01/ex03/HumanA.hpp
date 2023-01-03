/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:18:51 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/30 19:29:29 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#pragma once

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA(void);

	void	attack(void);

private:
	std::string	_name;
	Weapon&		_weapon;
};

#endif
