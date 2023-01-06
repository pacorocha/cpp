/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:18:01 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/05 23:27:50 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
  Zombie *zombies;
  int horde = 200;

  zombies = zombieHorde(horde, "Z");
  for (int i = 0; i < horde; i++)
	zombies[i].announce();
  delete[] zombies;
	return (0);
}
