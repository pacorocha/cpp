#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;
// Constructors
Fixed::Fixed()
{
	this->_raw_bits = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(const int integer) {
	this->_raw_bits = integer << Fixed::_fractional_bits;
}

Fixed::Fixed(const float float_number) {
	this->_raw_bits = roundf(float_number * (1 << Fixed::_fractional_bits));
}

// Destructor
Fixed::~Fixed() {}

// Operators
Fixed& Fixed::operator=(Fixed const&  rhs)
{
	this->_raw_bits= rhs.getRawBits();
	return *this;
}

std::ostream& operator<<( std::ostream& out, Fixed const& i ) {
	out << i.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const& rhs) const {
		return (_raw_bits > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const& rhs) const {
		return (_raw_bits < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const& rhs) const {
		return (_raw_bits >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const& rhs) const {
		return (_raw_bits <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const& rhs) const {
		return (_raw_bits == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const& rhs) const {
		return (_raw_bits != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const& rhs) const {
		return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& rhs) const {
		return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& rhs) const {
		return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& rhs) const {
		return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed Fixed::operator++(void) {
	++this->_raw_bits;
	return (Fixed(this->toFloat()));
}

Fixed Fixed::operator--(void) {
	--this->_raw_bits;
	return (Fixed(this->toFloat()));
}

Fixed Fixed::operator++(int) {
	Fixed inc_fixed(this->toFloat());
	++this->_raw_bits;
	return (inc_fixed);
}

Fixed Fixed::operator--(int) {
	Fixed dec_fixed(this->toFloat());
	--this->_raw_bits;
	return (dec_fixed);
}


Fixed const& Fixed::min(Fixed& value_one,  Fixed&  value_two) {
	if (value_one.getRawBits() < value_two.getRawBits())
		return (value_one);
	return (value_two);
}

Fixed const& Fixed::max(Fixed& value_one,  Fixed&  value_two) {
	if (value_one.getRawBits() > value_two.getRawBits())
		return (value_one);
	return (value_two);
}

Fixed const& Fixed::min(Fixed const& value_one,  Fixed const&  value_two) {
	if (value_one.getRawBits() < value_two.getRawBits())
		return (value_one);
	return (value_two);
}

Fixed const& Fixed::max(Fixed const& value_one,  Fixed const&  value_two) {
	if (value_one.getRawBits() > value_two.getRawBits())
		return (value_one);
	return (value_two);
}


// Methods
float	Fixed::toFloat( void ) const {
		return (static_cast<float>(this->_raw_bits) / (1 << Fixed::_fractional_bits));
}

int	Fixed::toInt( void ) const   {
	return (this->_raw_bits >> Fixed::_fractional_bits);
}

int		Fixed::getRawBits( void ) const {
		return (this->toFloat());
}

void	Fixed::setRawBits( int const raw ) {
		this->_raw_bits = raw <<  Fixed::_fractional_bits;
}
