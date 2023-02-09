#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form &copy);

		// Destructor
		~Form();

		// Operators
		Form & operator=(const Form &assign);

		// Getters
		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};

		// Methods
		void beSigned(const Bureaucrat& signer);

	private:
		std::string	_name;
		bool		_signed;
		int			_grade_to_sign;
		int			_grade_to_execute;
};

std::ostream & operator<<( std::ostream & o, Form const & rhs );

#endif