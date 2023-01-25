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
		~Animal();

		// Operators
		Animal & operator=(const Animal &assign);

		// Methods
		void		setType(std::string type);
		void		setSound(std::string sound);
		std::string	getType() const;
		std::string	getSound() const;
		void		makeSound() const;

	protected:
		std::string type;
		std::string sound;
};

#endif