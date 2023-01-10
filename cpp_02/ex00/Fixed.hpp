#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);

		// Destructor
		~Fixed();

		// Operators
		Fixed & operator=(const Fixed &assign);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixed_point_number_value;
		static int const	fractional_bits = 8;
};

#endif
