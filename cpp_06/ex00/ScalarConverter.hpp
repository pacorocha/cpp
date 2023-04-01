#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <iostream>
# include <cmath>
# include <cstdlib>

class ScalarConverter
{
	public:
		// Destructor
		~ScalarConverter(void);

		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);

		// Methods
		static void convert(const std::string& literal);

	private:
		// Constructors
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);

		// Attributes
		static std::string		_value;
		static int				_type;
		static std::string		_pseudoDoubles[4];
		static std::string		_pseudoFloats[4];
		static char				_valueAsChar;
		static int				_valueAsInt;
		static double			_valueAsDouble;
		static float			_valueAsFloat;

		// Accessors
		static void			_setValue(std::string value);
		static std::string	_getValue(void);
		static void			_setType(int const type);
		static int			_getType(void);

		// methods
		static void _printConversion(void);
		static void _printNonConversion(void);
		static void _checkType(void);
		static void _isPseudoDouble(void);
		static void _isPseudoFloat(void);
		static bool _isChar(std::string const &str);
		static bool _isInt(std::string const &str);
		static bool _isFloat(std::string const &str);
		static bool _isDouble(std::string const &str);
		static bool _checkSign(int i, std::string str);
		static void _toChar( void );
		static void _toInt( void );
		static void _toDouble(void);
		static void _toFloat(void);
		enum e_type
		{
			_UNSET,
			_PSEUDO_DOUBLE,
			_PSEUDO_FLOAT,
			_CHAR,
			_INT,
			_FLOAT,
			_DOUBLE
		};
};

#endif