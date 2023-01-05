/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:31:35 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/03 02:13:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#pragma once

# include <iostream>
# include <string>

class Weapon
{
public:
    Weapon(std::string type);
    ~Weapon(void);

	const std::string&	getType(void);
	void		setType(std::string);
private:
	std::string _type;
};

#endif
