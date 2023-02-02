#include "Form.hpp"

// Constructors
Form::Form() :
	_name("Nameless"),
	_signed(false),
	_grade_to_sign(150),
	_grade_to_execute(150) {
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) :
	_name(name),
	_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute) {
	verifyGrade(_grade_to_sign);
	verifyGrade(_grade_to_execute);
	std::cout << "\e[0;33mAttribute Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) {
	_name = copy.getName();
	_signed = copy.getSignedStatus();
	_grade_to_sign = copy.getGradeToSign();
	_grade_to_execute = copy.getGradeToExecute();
	verifyGrade(_grade_to_sign);
	verifyGrade(_grade_to_execute);
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

// Destructor
Form::~Form() {
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form & Form::operator=(const Form &assign) {
	(void) assign;
	return (*this);
}

// Getters
std::string Form::getName() const {
	return (_name);
}

bool Form::getSignedStatus() const {
	return (_signed);
}

int Form::getGradeToSign() const {
	return (_grade_to_sign);
}

int	Form::getGradeToExecute() const {
	return (_grade_to_execute);
}

// Exceptions
const char * Form::GradeTooHighException::what() const throw() {
	return "Grade too high, no form for you.";
}
const char * Form::GradeTooLowException::what() const throw() {
	return "Grade too low, no form for you.";
}

void Form::verifyGrade(int grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  }
  if (grade > 150) {
    throw GradeTooLowException();
  }
}

void Form::beSigned(const Bureaucrat& signer) {
	std::cout << "Checking if " + signer.getName() + " can sign the form..." << std::endl;
	if (signer.getGrade() <= this->_grade_to_sign) {
		std::cout << signer.getName() + " signed the form " + this->_name + "."<< std::endl;
		std::cout << std::endl;
		this->_signed = true;
	} else {
		std::cout << signer.getName() + " can't sign the form " + this->_name + "."<< std::endl;
		std::cout << std::endl;
	}
}

std::ostream & operator<<( std::ostream & o, Form const & rhs ) {
	o << "Printing form data..." << std::endl;
	o << "Name: " + rhs.getName() << std::endl;
	o << "Signed: " << std::boolalpha << rhs.getSignedStatus() << std::endl;
	o << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	o << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	o << "Finished printing form data." << std::endl;
	o << std::endl;
	return ( o );
}
