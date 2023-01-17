#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void)
{
	this->_raw_bits = 0;
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "\e[0;34mCopy assignment operator called of Fixed\e[0m" << std::endl;
	this->_raw_bits = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
		std::cout << "\e[0;35mgetRawBits member function called\e[0m" << std::endl;
		return (this->_raw_bits);
}

void	Fixed::setRawBits(int const raw) {
		this->_raw_bits = raw;
}
