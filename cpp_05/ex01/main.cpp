# include "Form.hpp"

int	main( void )
{
	Form a;
	Form b = Form("27 B", 3, 25);
	Bureaucrat klamm("Klamm", 5);
	Bureaucrat vp("VP", 2);
	std::cout << klamm;
	std::cout << std::endl;
	std::cout << "Creating form with grade -1..." << std::endl;
	try {
		Form c = Form("58 C", -1, 25);
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Creating form with grade 250..." << std::endl;
	try {
		Form d = Form("43 D", 1, 250);
	} catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	Form e = Form("63 E", 7, 150);
	std::cout << std::endl;
	std::cout << a;
	a = b;
	std::cout << b;
	std::cout << a;
	std::cout << e;
	std::cout << "Test if Klamm can sign b" << std::endl;
	b.beSigned(klamm);
	std::cout << std::endl;
	b.beSigned(vp);
	std::cout << std::endl;
	std::cout << b;
	klamm.signForm(e);
	std::cout << e;
	return ( 0 );
}
