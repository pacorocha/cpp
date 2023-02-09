#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		// Destructor
		virtual ~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);

		// Exceptions
		class FileOutputException : public std::exception {
			virtual const char* what() const throw();
		};

		// Methods
		void execute(Bureaucrat const & executor) const;

	private:

};

#endif