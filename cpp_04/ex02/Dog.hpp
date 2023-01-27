#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		// Constructors
		Dog(void);
		Dog(const Dog &copy);

		// Destructor
		virtual ~Dog(void);

		// Operators
		Dog & operator=(const Dog &assign);

		// Methods
		virtual void makeSound(void);

	private:
		Brain*	_brain;
};

#endif