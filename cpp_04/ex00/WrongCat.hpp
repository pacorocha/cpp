#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat(void);
		WrongCat(const WrongCat &copy);

		// Destructor
		~WrongCat();

		// Operators
		WrongCat & operator=(const WrongCat &assign);
};

#endif