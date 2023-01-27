#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		// Constructors
		Animal(void);
		Animal(const Animal &copy);

		// Destructor
		virtual ~Animal(void);

		// Operators
		Animal & operator=(const Animal &assign);

		// Methods
		void		setType(std::string type);
		void		setSound(std::string sound);
		std::string	getType(void) const;
		std::string	getSound(void) const;
		void		makeSound(void) const;

	protected:
		std::string type;
		std::string sound;
};

#endif