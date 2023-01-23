/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:33 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/22 22:01:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int	main(void) {
	ClapTrap r1d1("R1D1");
	ClapTrap r2d2("R2D2");
	ClapTrap r3d3;
	ClapTrap r4d4(r3d3);

	for (int i = 0; i <= 10; i++) {
		r1d1.attack(r2d2.getName());
		if (r1d1.getEnergyPoints() > 0)
			r2d2.takeDamage(r1d1.getAttackDamage());
		if (i % 2) {
			r2d2.beRepaired(3);
		}
		r2d2.attack(r3d3.getName());
		if (r2d2.getEnergyPoints() > 0)
			r3d3.takeDamage(r2d2.getAttackDamage());
	}
	r4d4.attack(r3d3.getName());
	r3d3.takeDamage(r4d4.getAttackDamage());
	r1d1.beRepaired(2);
	return (0);
}
