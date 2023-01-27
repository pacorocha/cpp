#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog(void);
		Dog(const Dog &copy);

		// Destructor
		virtual ~Dog(void);

		// Operators
		Dog & operator=(const Dog &assign);
};

#endif