# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main( void )
{
	ShrubberyCreationForm test("output");
	std::cout << test << std::endl;
	Bureaucrat smith("Smith", 140);
	std::cout << std::endl;
	smith.executeForm(test);
	std::cout << std::endl;
	smith.signForm(test);
	std::cout << std::endl;
	smith.executeForm(test);
	std::cout << std::endl;
	Bureaucrat coltrane("Coltrane", 120);
	coltrane.executeForm(test);
	std::cout << std::endl;
	Bureaucrat mulder("Mulder", 76);
	std::cout << std::endl;
	Bureaucrat scully("Scully", 43);
	std::cout << std::endl;
	RobotomyRequestForm marvin("Marvin");
	std::cout << std::endl;
	std::cout << marvin << std::endl;
	marvin.beSigned(mulder);
	std::cout << std::endl;
	scully.executeForm(marvin);
	std::cout << std::endl;
	std::cout << marvin << std::endl;
	scully.signForm(marvin);
	mulder.executeForm(marvin);
	std::cout << std::endl;
	mulder.executeForm(marvin);
	scully.executeForm(marvin);
	std::cout << std::endl;
	Bureaucrat smokingman("Smoking Man", 25);
	std::cout << std::endl;
	PresidentialPardonForm alien("Alien");
	alien.beSigned(smokingman);
	std::cout << std::endl;
	Bureaucrat lewinsky("Lewinsky", 5);
	std::cout << std::endl;
	lewinsky.executeForm(alien);
	std::cout << std::endl;
	return ( 0 );
}
