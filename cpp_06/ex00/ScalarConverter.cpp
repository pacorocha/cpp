#include "ScalarConverter.hpp"

std::string ScalarConverter::_value = "";
int			ScalarConverter::_type = 0;
char		ScalarConverter::_valueAsChar = 0;
int			ScalarConverter::_valueAsInt = 0;
double		ScalarConverter::_valueAsDouble = 0;
float		ScalarConverter::_valueAsFloat = 0;

std::string ScalarConverter::_pseudoDoubles[4] = {
	"nan",
	"inf",
	"+inf",
	"-inf"
};

std::string ScalarConverter::_pseudoFloats[4] = {
	"nanf",
	"inff",
	"+inff",
	"-inff"
};

// Constructors
ScalarConverter::ScalarConverter(void) {
	_value = "";
	_type = _UNSET;
	_valueAsChar = 0;
	_valueAsInt = 0;
	_valueAsDouble = 0;
	_valueAsFloat = 0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}

// Destructor
ScalarConverter::~ScalarConverter(void) {}

// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &rhs)
{
	if (this != &rhs) {
		this->_setValue(rhs._getValue());
		this->_setType(rhs._getType());
		this->_valueAsChar = rhs._valueAsChar;
		this->_valueAsInt = rhs._valueAsInt;
		this->_valueAsDouble = rhs._valueAsDouble;
		this->_valueAsFloat = rhs._valueAsFloat;
	}
	return *this;
}

// Accessors
void	ScalarConverter::_setValue(std::string const value) {
	_value = value;
}

std::string	ScalarConverter::_getValue(void) {
	return (_value);
}

void	ScalarConverter::_setType(int const type) {
	_type = type;
}

int	ScalarConverter::_getType(void) {
	return(_type);
}

// Methods
void ScalarConverter::convert(const std::string& literal) {
	_setValue(literal);
	_checkType();
	if (_getType() == _UNSET || _getType() == _PSEUDO_DOUBLE || _getType() == _PSEUDO_FLOAT)
		_printNonConversion();
	else
		_printConversion();
}

void ScalarConverter::_checkType(void) {
	_isPseudoDouble();
	_isPseudoFloat();
	_isChar(_value);
	_isInt(_value);
	_isDouble(_value);
	_isFloat(_value);
}

void ScalarConverter::_printConversion(void) {
	if (!_valueAsInt || !isprint(_valueAsChar))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _valueAsChar << "'" << std::endl;
	std::cout << "int: " <<  _valueAsInt << std::endl;
	std::cout << "float: " << _valueAsFloat << std::endl;
	std::cout << "double: " << _valueAsDouble << std::endl;
}

void ScalarConverter::_printNonConversion(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_getType() == _PSEUDO_DOUBLE) {
		std::cout << "float: " << _value << "f" << std::endl;
		std::cout << "int: " <<  _value << std::endl;
	}
	else if (_getType() == _PSEUDO_FLOAT) {
		std::cout << "float: " << _value << std::endl;
		std::cout << "int: " <<  _value.substr(0, _value.size()-1) << std::endl;
	}
	else {
		std::cout << "float: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
}

bool ScalarConverter::_checkSign(int i, std::string str) {
	if (i == 0 && str[i] == '-')
		return (true);
	return(false);
}

void ScalarConverter::_isPseudoDouble(void) {
	for (int i = 0; i < 4; i++) {
		if (_getValue() == _pseudoDoubles[i]) {
			_setType(_PSEUDO_DOUBLE);
			return ;
		}
	}
}

void ScalarConverter::_isPseudoFloat(void) {
	for (int i = 0; i < 4; i++) {
		if (_getValue() == _pseudoFloats[i]) {
			_setType(_PSEUDO_FLOAT);
			return ;
		}
	}
}

bool ScalarConverter::_isChar(std::string const &str) {
	if (str.length() == 1 && !std::isdigit(str[0])) {
		_toChar();
		return (true);
	}
	else
		return (false);
}

bool ScalarConverter::_isInt(std::string const &str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (_checkSign(i, str))
			continue ;
		if (!std::isdigit(str[i]))
			return (false);
	}
	_toInt();
	return (true);
}

bool ScalarConverter::_isFloat(std::string const &str) {
	if (!str.find_last_of('f'))
		return (false);
	for (size_t i = 0; i < str.length(); i++) {
		if (_checkSign(i, str))
			continue ;
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (false);
	}
	_toFloat();
	return (true);
}

bool ScalarConverter::_isDouble(std::string const &str) {
	if (!str.find_first_of('.'))
		return (false);
	for (size_t i = 0; i < str.length(); i++) {
		if(_checkSign(i, str))
			continue ;
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
	}
	_toDouble();
	return (true);
}

void ScalarConverter::_toChar(void)
{
	_setType(_CHAR);
	_valueAsChar = static_cast<char>(_value[0]);
	_valueAsInt = static_cast<int>(_valueAsChar);
	_valueAsFloat = static_cast<float>(_valueAsChar);
	_valueAsDouble = static_cast<double>(_valueAsChar);
}

void ScalarConverter::_toInt(void) {
	_setType(_INT);
	_valueAsInt = static_cast<int>(atoi(_value.c_str()));
	_valueAsChar = static_cast<char>(_valueAsInt);
	_valueAsFloat = static_cast<float>(_valueAsInt);
	_valueAsDouble = static_cast<double>(_valueAsInt);
}

void ScalarConverter::_toDouble(void) {
	_setType(_DOUBLE);
	_valueAsDouble = static_cast<double>(strtod(_value.c_str(), NULL));
	_valueAsInt = static_cast<int>(_valueAsDouble);
	_valueAsChar = static_cast<char>(_valueAsDouble);
	_valueAsFloat = static_cast<float>(_valueAsDouble);
}

void ScalarConverter::_toFloat(void) {
	_setType(_FLOAT);
	_valueAsFloat = static_cast<float>(atof(_value.c_str()));
	_valueAsDouble = static_cast<double>(_valueAsFloat);
	_valueAsInt = static_cast<int>(_valueAsFloat);
	_valueAsChar = static_cast<char>(_valueAsFloat);
}
