#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm &copy);

		// Destructor
		virtual ~AForm();

		// Operators
		AForm & operator=(const AForm &assign);

		// Setters
		void	setName(std::string name);
		void	setGradeToSign(int grade);
		void	setGradeToExecute(int grade);
		void	setTarget(std::string target);
		void	setSignedStatus(bool status);

		// Getters
		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		std::string	getTarget() const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
			const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
			const char* what() const throw();
		};

		// Methods
		void			beSigned(const Bureaucrat& signer);
		bool			execute(Bureaucrat const& executor) const;
		virtual void	formAction(const AForm& form) const = 0;

	private:
		std::string	_name;
		bool		_signed;
		int			_grade_to_sign;
		int			_grade_to_execute;
		std::string _target;
};

std::ostream & operator<<( std::ostream & o, AForm const & rhs );

#endif