#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() {
	this->setName("Shrubbery Creation Form");
	this->setGradeToSign(145);
	this->setGradeToExecute(137);
	this->setTarget("None");
	this->setSignedStatus(false);
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) {
	this->setName("Shrubbery Creation Form");
	this->setGradeToSign(145);
	this->setGradeToExecute(137);
	this->setGradeToSign(145);
	this->setGradeToExecute(137);
	this->setTarget(target);
	std::cout << "\e[0;33mTarget Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm() {
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
	*this = copy;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign) {
	std::cout << "\e[0;33mCopy operator called of ShrubberyCreationForm\e[0m" << std::endl;
	this->setSignedStatus(assign.getSignedStatus());
	return (*this);
}

// Exceptions
const char * ShrubberyCreationForm::FileOutputException::what() const throw() {
	return "Error while printing the file.";
}

// Methods
void ShrubberyCreationForm::formAction(const AForm& form) const {
	std::ofstream	outputFile(this->getTarget().append("_shrubbery").c_str());
	std::string trees =
		"               ,@@@@@@@,\n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888|88/8o\n"
		"   ,%&|%&&%&&%,@@@|@@@/@@@88|88888/88'\n"
		"   %&&%&%&/%&&%@@|@@/ /@@@88888|88888'\n"
		"   %&&%/ %&%%&&@@| V /@@' `88|8 `/88'\n"
		"   `&%| ` /%&'    |.|        | '|8'\n"
		"       |o|        | |         | |\n"
		"       |.|        | |         | |\n"
		"jgs__ ||/ ._|//_/__/  ,|_//__||/.  |_//__/_\n";
	if (outputFile.fail())
		throw ShrubberyCreationForm::FileOutputException();
	outputFile << trees;
	outputFile.close();
	std::cout << form.getName() + " was executed." << std::endl;
	std::cout << "File: "+ form.getTarget() + "_shrubbery created." << std::endl;
}

