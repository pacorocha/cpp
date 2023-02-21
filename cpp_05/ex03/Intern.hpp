#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
	typedef AForm* (Intern::* createFormPointer)(std::string) const;
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);

		// Destructor
		~Intern();

		// Operators
		Intern & operator=(const Intern &assign);

		// Methods
		AForm* makeForm(std::string name, std::string target);

	private:
		static	std::string _formName[3];
		static	createFormPointer _createForm[3];
		AForm*	_createShrubberyForm(std::string target) const;
		AForm*	_createRobotomyForm(std::string target) const;
		AForm*	_createPresidentialForm(std::string target) const;
};

#endif