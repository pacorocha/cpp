#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() :
	_name("John") {
	_grade = 0;
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
	_name(copy.getName()) {
	_grade = copy.getGrade();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "\e[0;33mFields name and grade Constructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign) {
	_grade = assign.getGrade();
	return (*this);
}

// Getters
std::string Bureaucrat::getName() const {
	return (_name);
}
int Bureaucrat::getGrade() const {
	return (_grade);
}

// Exceptions
const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high, nothing done.";
}
const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low, nothing done.";
}

// Methods
void Bureaucrat::incrementGrade() {
	std::cout << "Incrementing grade..." << std::endl;
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade() {
	std::cout << "Decrementing grade..." << std::endl;
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	}
	catch(const std::exception& e) {
		std::cerr << this->_name + " cannot sign " + form.getName() + ". " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name + " signs " + form.getName() << std::endl;
	std::cout << std::endl;
	return ;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs ) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
