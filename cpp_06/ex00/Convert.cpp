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

bool Convert::*_isChar(std::string const &str) {

}

bool Convert::_isInt(std::string const &str) {
}

bool Convert::_isFloat(std::string const &str) {
}

bool Convert::_isDouble(std::string const &str) {
}



