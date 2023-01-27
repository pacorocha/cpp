#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		// Constructors
		AAnimal(void);
		AAnimal(const AAnimal &copy);

		// Destructor
		virtual ~AAnimal(void);

		// Operators
		AAnimal & operator=(const AAnimal &assign);

		// Methods
		void		setType(std::string type);
		void		setSound(std::string sound);
		std::string	getType(void) const;
		std::string	getSound(void) const;
		virtual void makeSound(void) = 0;

	protected:
		std::string type;
		std::string sound;
};

#endif