#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		// Destructor
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);

		// Methods
		virtual void	formAction(const AForm& form) const;

	private:

};

#endif