#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c( 10 );
	Fixed d( 2 );

	std::cout << c * d << std::endl;
	std::cout <<  c / d << std::endl;
	std::cout <<  d  << std::endl;
	std::cout <<  --d  << std::endl;
	std::cout <<  d  << std::endl;
	std::cout <<  d--  << std::endl;
	std::cout <<  d  << std::endl;

	Fixed e( 5 );
	Fixed f( 5 );
	Fixed g( 10 );
	std::cout << std::boolalpha << "expected: true " << (e == f)  << std::endl;
	std::cout << std::boolalpha << "expected: false " << (e != f)  << std::endl;

	std::cout << std::boolalpha << "expected: false " << (e > g)  << std::endl;
	std::cout << std::boolalpha << "expected: true " << (e < g)  << std::endl;

	std::cout << "expected: min 5:  " << Fixed::min(10, 5) << std::endl;

	return 0;
}
