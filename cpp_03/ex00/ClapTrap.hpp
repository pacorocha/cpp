/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:27 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/22 23:09:28 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		// Constructors
		ClapTrap(void);
		ClapTrap(std::string const& name);
		ClapTrap(const ClapTrap& copy);

		// Destructor
		~ClapTrap();

		// Operators
		ClapTrap & operator=(const ClapTrap& assign);

		// Methods
		void		setName(std::string const &name);
		void		setHitPoints(int amount);
		void		setEnergyPoints(int amount);
		void		setAttackDamage(int amount);
		void		setModel(std::string const &model);

		int			getAttackDamage(void) const;
		int			getEnergyPoints(void) const;
		int			getHitPoints(void) const;
		std::string	getName(void) const;
		std::string	getModel(void) const;

		void 		attack(const std::string& target);
		void 		takeDamage(int amount);
		void 		beRepaired(int amount);

	protected:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
		std::string	_model;
};

#endif
