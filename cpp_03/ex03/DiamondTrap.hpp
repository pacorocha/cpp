#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		// Constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);

		// Destructor
		~DiamondTrap();

		// Operators
		DiamondTrap & operator=(const DiamondTrap &assign);

		// Methods
		std::string	get_Name(void) const;
		void		attack(const std::string& target);
		void		whoAmI(void);

	private:
		std::string	_name;
};

#endif