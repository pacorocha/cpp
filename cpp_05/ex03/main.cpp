#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main( void )
{
	AForm* form;
	Intern someIntern;
	Bureaucrat lewinsky("Lewinsky", 5);

	form = someIntern.makeForm("shrubbery creation", "home");
	form->beSigned(lewinsky);
	lewinsky.executeForm(*form);
	delete form;
	form = someIntern.makeForm("robotomy request", "marvin");
	lewinsky.signForm(*form);
	lewinsky.executeForm(*form);
	delete form;
	form = someIntern.makeForm("presidential pardon", "Me");
	lewinsky.signForm(*form);
	lewinsky.executeForm(*form);
	delete form;
	form = someIntern.makeForm("42 exam request", "Cadet");
	return ( 0 );
}
