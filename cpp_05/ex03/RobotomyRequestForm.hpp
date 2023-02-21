#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);

		// Destructor
		~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);

		// Methods
		virtual void	formAction(const AForm& form) const;

	private:

};

#endif