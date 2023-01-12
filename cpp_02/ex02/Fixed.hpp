#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(Fixed const& copy);
		Fixed(const int integer);
		Fixed(const float float_number);

		// Destructor
		~Fixed();

		// Operators
		Fixed&	operator=(Fixed const& rhs);
		bool	operator>(Fixed const& rhs) const;
		bool	operator<(Fixed const& rhs) const;
		bool	operator>=(Fixed const& rhs) const;
		bool	operator<=(Fixed const& rhs) const;
		bool	operator==(Fixed const& rhs) const;
		bool	operator!=(Fixed const& rhs) const;
		Fixed	operator+(Fixed const& rhs) const;
		Fixed	operator-(Fixed const& rhs) const;
		Fixed	operator*(Fixed const& rhs) const;
		Fixed	operator/(Fixed const& rhs) const;
		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed const& min(Fixed& value_one,  Fixed&  value_two);
		static Fixed const& max(Fixed& value_one,  Fixed&  value_two);
		static Fixed const& min(Fixed const& value_one,  Fixed const&  value_two);
		static Fixed const& max(Fixed const& value_one,  Fixed const&  value_two);

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
