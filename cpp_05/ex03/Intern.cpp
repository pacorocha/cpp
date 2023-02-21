#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string Intern::_formName[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::createFormPointer Intern::_createForm[3] = {
	&Intern::_createShrubberyForm,
	&Intern::_createRobotomyForm,
	&Intern::_createPresidentialForm
};

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	for (int i = 0; i < 3; i++) {
		if (name == this->_formName[i])
			return (this->*_createForm[i])(target);
	}
	std::cout << "Form " << name << " is not a valid form." << std::endl;
	return NULL;
}

AForm*	Intern::_createShrubberyForm(std::string target) const {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_createRobotomyForm(std::string target) const {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_createPresidentialForm(std::string target) const {
	return (new PresidentialPardonForm(target));
}
