#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm()
{
	this->setName("Presidential Pardon Form");
	this->setGradeToSign(25);
	this->setGradeToExecute(5);
	this->setTarget("None");
	this->setSignedStatus(false);
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) {
	this->setName("Presidential Pardon Form");
	this->setGradeToSign(25);
	this->setGradeToExecute(5);
	this->setTarget(target);
	this->setSignedStatus(false);
	std::cout << "\e[0;33mTarget Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm() {
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
	*this = copy;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	std::cout << "\e[0;33mCopy operator called of PresidentialPardonForm\e[0m" << std::endl;
	this->setSignedStatus(assign.getSignedStatus());
	return (*this);
}

// Methods
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if(this->canExecute(executor)) {
	std::cout << this->getTarget() + " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << this->getName() + " executed by " + executor.getName() + "." << std::endl;
	} else {
		std::cout << this->getName() + " couldn't be executed by " + executor.getName() + "." << std::endl;
	}
}
