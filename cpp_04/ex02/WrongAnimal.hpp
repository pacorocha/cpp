#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);

		// Destructor
		~WrongAnimal(void);

		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);

		// Methods
		std::string	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string type;
};

#endif