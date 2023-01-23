/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:33 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/18 22:26:38 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int	main(void) {
	ClapTrap r1d1("R1D1");
	ClapTrap r2d2("R2D2");
	ClapTrap r3d3;
	ClapTrap r4d4(r3d3);
	ScavTrap c3po("C3PO");
	FragTrap e8t88("8t88");

	for (int i = 0; i <= 10; i++) {
		c3po.attack(r1d1.getName());
		r1d1.takeDamage(c3po.getAttackDamage());
		r1d1.attack(r2d2.getName());
		r2d2.takeDamage(r1d1.getAttackDamage());
		if (i % 2) {
			r2d2.beRepaired(3);
			e8t88.attack(c3po.getName());
			c3po.takeDamage(e8t88.getAttackDamage());
		}
		r2d2.attack(r3d3.getName());
		r3d3.takeDamage(r2d2.getAttackDamage());
	}
	r1d1.beRepaired(2);
	c3po.attack(r2d2.getName());
	r1d1.takeDamage(c3po.getAttackDamage());
	c3po.guardGate();
	return (0);
}
