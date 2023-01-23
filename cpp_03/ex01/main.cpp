/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:33 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/23 20:01:40 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int	main(void) {
	ClapTrap r1d1("R1D1");
	ClapTrap r2d2("R2D2");
	ClapTrap r3d3;
	ScavTrap c3po("C3PO");

	for (int i = 0; i <= 10; i++) {
		c3po.attack(r1d1.getName());
		r1d1.takeDamage(c3po.getAttackDamage());
		c3po.attack(r2d2.getName());
		r2d2.takeDamage(c3po.getAttackDamage());
		if (i % 2) {
			r2d2.beRepaired(3);
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
