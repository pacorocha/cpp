#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
#include "Fixed.hpp"

class Point
{
	public:
		// Constructors
		Point(void);
		Point(float const x, float const y);
		Point(const Point& copy);

		// Destructor
		~Point(void);

		// Operators
		Point& operator=(Point const& assign);

		// Methods
		void			setX(Fixed const x);
		void			setY(Fixed const y);
		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;

	private:

		Fixed const _x;
		Fixed const _y;
};

#endif