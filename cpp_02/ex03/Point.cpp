#include "Point.hpp"

// Constructors
Point::Point(void) : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point& copy)
{
	*this = copy;
}

// Destructor
Point::~Point() {}


// Operators
Point& Point::operator=(Point const& assign)
{
	const_cast<Fixed &>(this->_x) = assign.getX();
	const_cast<Fixed &>(this->_y) = assign.getY();
	return (*this);
}

// Methods
void	Point::setX(Fixed const x) {
	const_cast<Fixed &>(this->_x) = x;
}

void	Point::setY(Fixed const y) {
	const_cast<Fixed &>(this->_y) = y;
}

Fixed const& Point::getX(void) const {
		return(this->_x);
}

Fixed const& Point::getY(void) const {
		return(this->_y);
}
