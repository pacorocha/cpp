/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:18:01 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/06 03:15:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie zombieinstack("Eenie");
	Zombie* zombieinheap;

	zombieinheap = zombieinstack.newZombie("Meenie");
	zombieinstack.announce();
	zombieinheap->announce();
	zombieinstack.randomChump("Miney");
	zombieinheap->randomChump("Mo");
	delete zombieinheap;
	return (0);
}
