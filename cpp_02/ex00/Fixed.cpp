#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	this->_fixed_point_number_value = 0;
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	this->_fixed_point_number_value = copy.getRawBits();
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	(void) assign;
	std::cout << "\e[0;34mCopy assignment operator called of Fixed\e[0m" << std::endl;
	this->_fixed_point_number_value = assign.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const {
		std::cout << "\e[0;35mgetRawBits member function called\e[0m" << std::endl;
		return (this->_fixed_point_number_value);
}

void	Fixed::setRawBits( int const raw ) {
		this->_fixed_point_number_value = raw;
}
