/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:40:31 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/06 03:16:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  Zombie* zombies = new Zombie[N];
  std::string id;
  std::string newName;

  for (int i = 0; i < N; i++) {
  	std::ostringstream convert;
	convert << i + 1;
	id = convert.str();
	newName = name + id;
    zombies[i].setName(newName);
  }
  return (zombies);
}
