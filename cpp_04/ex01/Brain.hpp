#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain(void);
		Brain(const Brain &copy);

		// Destructor
		~Brain(void);

		// Operators
		Brain & operator=(const Brain &assign);

	private:
		static std::string	ideas[100];
};

#endif