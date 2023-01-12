#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;
// Constructors
Fixed::Fixed()
{
	this->_raw_bits = 0;
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int integer) {
	std::cout << "\e[0;33mInt argument Constructor called\e[0m" << std::endl;
	this->_raw_bits = integer <<   Fixed::_fractional_bits;
}

Fixed::Fixed(const float float_number) {
	std::cout << "\e[0;33mFloat argument Constructor called\e[0m" << std::endl;
	this->_raw_bits = roundf(float_number * (1 << Fixed::_fractional_bits));
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "\e[0;34mCopy assignment operator called\e[0m" << std::endl;
	this->_raw_bits = assign.getRawBits();
	return *this;
}

std::ostream &operator<<( std::ostream &out, Fixed const &i ) {
	out << i.toFloat();
	return (out);
}

// Methods
float	Fixed::toFloat( void ) const {
		return static_cast<float>(this->_raw_bits) / (1 << Fixed::_fractional_bits);
}

int	Fixed::toInt( void ) const   {
	return this->_raw_bits >> Fixed::_fractional_bits;
}

int		Fixed::getRawBits( void ) const {
		return (this->_raw_bits);
}

void	Fixed::setRawBits( int const raw ) {
		this->_raw_bits = raw;
}
