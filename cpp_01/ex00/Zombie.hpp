/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:36:21 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/06 03:15:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#pragma once

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie(std::string name);
    ~Zombie(void);

	void		announce(void);
	Zombie*		newZombie(std::string name);
	static void	randomChump(std::string name);

private:
	std::string	_name;
};

#endif
