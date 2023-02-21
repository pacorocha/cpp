#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm()
{
	this->setName("Robotomy Request Form");
	this->setGradeToSign(72);
	this->setGradeToExecute(45);
	this->setTarget("None");
	this->setSignedStatus(false);
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) {
	this->setName("Robotomy Request Form");
	this->setGradeToSign(72);
	this->setGradeToExecute(45);
	this->setTarget(target);
	this->setSignedStatus(false);
	std::cout << "\e[0;33mTarget Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm() {
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
	*this = copy;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	std::cout << "\e[0;33mCopy operator called of RobotomyRequestForm\e[0m" << std::endl;
	this->setSignedStatus(assign.getSignedStatus());
	return (*this);
}

void RobotomyRequestForm::formAction(const AForm& form) const {
	srand(time(0));
	std::cout << "bzzzzzzzzzzzzz..." << std::endl;
	std::cout << "bzzzzzz... bzzzzz..." << std::endl;
	std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ!!!" << std::endl;
		if (rand() % 2 == 0)
			std::cout << "ROBOTOMY WAS SUCCESSFUL!" << std::endl;
		else
			std::cout << "ROBOTOMY FAILED... MISERABLY" << std::endl;
	std::cout << form.getName() + " was executed." << std::endl;
}
