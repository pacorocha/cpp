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
		~WrongAnimal();

		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);

		// Methods
		std::string	getType() const;
		void		makeSound() const;

	protected:
		std::string type;
};

#endif