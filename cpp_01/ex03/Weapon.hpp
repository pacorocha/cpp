/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:31:35 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/29 19:57:22 by jfrancis         ###   ########.fr       */
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