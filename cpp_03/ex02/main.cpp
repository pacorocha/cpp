/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:33 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/23 20:01:34 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int	main(void) {
	ClapTrap r1d1("R1D1");
	ClapTrap r2d2("R2D2");
	ClapTrap r3d3;
	ScavTrap c3po("C3PO");
	FragTrap e8t88("8t88");

	for (int i = 0; i <= 10; i++) {
		e8t88.attack(c3po.getName());
		if (e8t88.getEnergyPoints() > 0)
			c3po.takeDamage(e8t88.getAttackDamage());
		c3po.attack(r1d1.getName());
		if (c3po.getEnergyPoints() > 0)
			r1d1.takeDamage(c3po.getAttackDamage());
		r1d1.attack(r2d2.getName());
		if (r1d1.getEnergyPoints() > 0)
			r2d2.takeDamage(r1d1.getAttackDamage());
		if (i % 2) {
			r2d2.beRepaired(3);
			e8t88.attack(c3po.getName());
			if (e8t88.getEnergyPoints() > 0)
				c3po.takeDamage(e8t88.getAttackDamage());
		}
		r2d2.attack(r3d3.getName());
		if (r2d2.getEnergyPoints() > 0)
			r3d3.takeDamage(r2d2.getAttackDamage());
	}
	r1d1.beRepaired(2);
	c3po.attack(r2d2.getName());
	if (c3po.getEnergyPoints() > 0)
		r1d1.takeDamage(c3po.getAttackDamage());
	c3po.guardGate();
	e8t88.highFivesGuys();
	return (0);
}
