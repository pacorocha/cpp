# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main( void )
{
	ShrubberyCreationForm test("output");
	std::cout << test << std::endl;
	Bureaucrat smith("Smith", 140);
	std::cout << std::endl;
	test.execute(smith);
	std::cout << std::endl;
	test.beSigned(smith);
	std::cout << std::endl;
	Bureaucrat coltrane("Coltrane", 120);
	test.execute(coltrane);
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
	marvin.execute(scully);
	std::cout << std::endl;
	std::cout << marvin << std::endl;
	marvin.beSigned(scully);
	marvin.execute(mulder);
	std::cout << std::endl;
	marvin.execute(scully);
	std::cout << std::endl;
	Bureaucrat smokingman("Smoking Man", 25);
	std::cout << std::endl;
	PresidentialPardonForm alien("Alien");
	alien.beSigned(smokingman);
	std::cout << std::endl;
	Bureaucrat lewinsky("Lewinsky", 5);
	std::cout << std::endl;
	alien.execute(lewinsky);
	std::cout << std::endl;
	return ( 0 );
}
