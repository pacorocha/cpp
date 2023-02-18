#include "AForm.hpp"

// Constructors
AForm::AForm() :
	_name("Nameless"),
	_signed(false),
	_grade_to_sign(150),
	_grade_to_execute(150),
	_target("None") {
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) :
	_name(name),
	_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute) {
	if (_grade_to_sign < 1) {
		throw GradeTooHighException();
	}
	if (_grade_to_sign > 150) {
		throw GradeTooLowException();
	}
	std::cout << "\e[0;33mAttribute Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy) {
	_name = copy.getName();
	_signed = copy.getSignedStatus();
	_grade_to_sign = copy.getGradeToSign();
	_grade_to_execute = copy.getGradeToExecute();
	if (_grade_to_sign < 1) {
		throw GradeTooHighException();
	}
	if (_grade_to_sign > 150) {
		throw GradeTooLowException();
	}
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

// Destructor
AForm::~AForm() {
	std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}

// Operators
AForm& AForm::operator=(const AForm &assign) {
	std::cout << "\e[0;33mCopy operator called of AForm\e[0m" << std::endl;
	this->_signed = assign.getSignedStatus();
	return (*this);
}

// Setters
void	AForm::setName(std::string name) {
	this->_name = name;
}

void	AForm::setGradeToSign(int grade) {
	this->_grade_to_sign = grade;
}
void	AForm::setGradeToExecute(int grade) {
	this->_grade_to_execute = grade;
}

void	AForm::setTarget(std::string target) {
	this->_target = target;
}

void	AForm::setSignedStatus(bool status) {
	this->_signed = status;
}

// Getters
std::string AForm::getName() const {
	return (_name);
}

bool AForm::getSignedStatus() const {
	return (_signed);
}

int AForm::getGradeToSign() const {
	return (_grade_to_sign);
}

int	AForm::getGradeToExecute() const {
	return (_grade_to_execute);
}

std::string	AForm::getTarget() const {
	return (_target);
}

// Exceptions
const char * AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.\n";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.\n";
}

const char* AForm::FormNotSignedException::what( void ) const throw() {
	return ( "Form is not signed, go get it signed and bring it back after that.\n" );
}

// Methods
void AForm::beSigned(const Bureaucrat& signer) {
	std::cout << "Checking if " + signer.getName() + " can sign the " + this->_name + "..." << std::endl;
	if (this->_signed == true) {
		std::cout << "Form is already signed.\n";
		return ;
	} else {
		try {
			if (signer.getGrade() > this->getGradeToSign())
				throw AForm::GradeTooLowException();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			return;
		}
		this->_signed = true;
		std::cout << this->getName() + " was signed by " + signer.getName() << std::endl;
		std::cout << std::endl;
		return ;
	}
}

bool AForm::execute(const Bureaucrat& executor) const {
	std::cout << executor.getName() + " tries to execute " + this->getName() + "." << std::endl;
	if (this->getSignedStatus() == false) {
		throw AForm::FormNotSignedException();
		return (false);
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
		return (false);
	}
	return (true);
}

std::ostream & operator<<( std::ostream & o, AForm const & rhs ) {
	o << "Printing form data..." << std::endl;
	o << "Name: " + rhs.getName() << std::endl;
	o << "Signed: " << std::boolalpha << rhs.getSignedStatus() << std::endl;
	o << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	o << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	o << "Finished printing " + rhs.getName() + " data." << std::endl;
	o << std::endl;
	return ( o );
}
