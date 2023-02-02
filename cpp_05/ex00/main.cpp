# include "Bureaucrat.hpp"

int	main( void )
{
	try {
		Bureaucrat topgrade = Bureaucrat("Bert", 1);
		Bureaucrat copy;
		copy = topgrade;
		std::cout << topgrade;
		std::cout << copy;
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat worstgrade = Bureaucrat("Wort", 150);
		Bureaucrat copy(worstgrade);
		std::cout << worstgrade;
		std::cout << copy;
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "Creating Bureaucrat with grade 0 ..." << std::endl;
		Bureaucrat worstgrade = Bureaucrat("Wort", 0);
		std::cout << worstgrade;
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat topgrade = Bureaucrat("Bert", 1);
		std::cout << topgrade;
		topgrade.incrementGrade();
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat worstgrade = Bureaucrat("Wort", 150);
		std::cout << worstgrade;
		worstgrade.decrementGrade();
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "Creating Bureaucrat with grade -1..." << std::endl;
		Bureaucrat belowzero = Bureaucrat("Wort", -1);
		std::cout << belowzero;
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "Creating Bureaucrat with grade 151..." << std::endl;
		Bureaucrat overmax = Bureaucrat("Wort", 151);
		std::cout << overmax;
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return ( 0 );
}
