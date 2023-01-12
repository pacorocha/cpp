#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed& copy);

		// Destructor
		~Fixed();

		// Operators
		Fixed& operator=(const Fixed& rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_raw_bits;
		static const int	_fractional_bits = 8;
};

#endif
