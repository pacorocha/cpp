#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed(const int integer);
		Fixed(const float float_number);

		// Destructor
		~Fixed(void);

		// Operators
		Fixed& operator=(const Fixed& rhs);

		// Methods
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_raw_bits;
		static const int	_fractional_bits;
};

std::ostream& operator<<( std::ostream& out, Fixed const& i );

#endif
