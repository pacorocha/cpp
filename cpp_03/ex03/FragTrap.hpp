#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);

		// Destructor
		~FragTrap();

		// Operators
		FragTrap & operator=(const FragTrap &assign);

		// Methods
		void highFivesGuys(void);

};

#endif