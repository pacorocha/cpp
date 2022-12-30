/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:36:21 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/29 19:54:13 by jfrancis         ###   ########.fr       */
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
    Zombie(void);
    ~Zombie(void);

	void	announce(void);
	void	setName(std::string name);


private:
	std::string	_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
