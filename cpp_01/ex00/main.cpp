/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:18:01 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/28 19:55:50 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
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