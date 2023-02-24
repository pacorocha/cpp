#include "Convert.hpp"

std::string Convert::_pseudoLiterals[8] = {
	"nan",
	"inf",
	"+inf",
	"-inf",
	"nanf",
	"inff",
	"+inff",
	"-inff"
};

std::string Convert::_validTypes[4] = {
	"CHAR",
	"INT",
	"FLOAT",
	"DOUBLE"
};

Convert::isOfTypePointer Convert::_isOfType[4] = {
	&Convert::_isChar,
	&Convert::_isInt,
	&Convert::_isFloat,
	&Convert::_isDouble
};

// Constructors
Convert::Convert(void) {}

Convert::Convert(std::string str) :
	_value(str) {
	this->runConverter();
}

Convert::Convert(const Convert &copy) {
	*this = copy;
}

// Destructor
Convert::~Convert(void) {}

// Operators
Convert & Convert::operator=(const Convert &rhs)
{
	this->_value = rhs._value;
	return *this;
}

// Exceptions
const char * Convert::TypeNotValidException::what() const throw() {
	return "Type conversion is impossible.";
}

// Accessors
std::string	Convert::getValue(void) {
	return (this->_value);
}

void	Convert::setType(std::string type) {
	this->_type = type;
}

// Methods
void Convert::runConverter(void) {
	this->_checkType();
}

void Convert::_checkType(void) {
	std::string value = this->getValue();
	for (int i = 0; i < 8; i++) {
		if (value.compare(_pseudoLiterals[i])) {
			this->_isPseudoLiteral = true;
			this->setType("PSEUDO");
			return ;
		}
	}
	for (int i = 0; i < 4; i++) {
		if ((this->*_isOfType[i])(value))
			this->setType(_validTypes[i]);
	}
}

bool Convert::_checkSign(int i, std::string str) {
	if (i == 0 && str[i] == '-')
		return (true);
	return(false);
}

bool Convert::_isChar(std::string const &str) {
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	else
		return (false);
}

bool Convert::_isInt(std::string const &str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (_checkSign(i, str))
			if (!std::isdigit(str[i]))
				return (false);
	}
	return (true);
}

bool Convert::_isFloat(std::string const &str) {
	if (str.find('f') == std::string::npos)
		return (false);
	for (size_t i = 0; i < str.length(); i++) {
		if (_checkSign(i, str))
			if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
				return (false);
	}
	return (true);
}

bool Convert::_isDouble(std::string const &str) {
	if (str.find('.') == std::string::npos)
		return (false);
	for (size_t i = 0; i < str.length())
		if(_checkSign(i, str))
			if (!std::isdigit(str[i]) && str[i] != '.')
				return (false);
	return (true);
}



