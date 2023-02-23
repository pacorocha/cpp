#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Convert
{
	typedef bool (Convert::* isOfTypePointer)(std::string const &str);

	public:
		// Constructors
		Convert(void);
		Convert(std::string str);
		Convert(const Convert &copy);

		// Destructor
		~Convert(void);

		// Operators
		Convert & operator=(const Convert &assign);

		// Exceptions
		class TypeNotValidException : public std::exception {
			virtual const char* what() const throw();
		};

		// Accessors
		std::string	getValue(void);
		void		setType(std::string type);

		// Methods
		void runConverter(void);

	private:
		std::string				_value;
		std::string				_type;
		static std::string		_pseudoLiterals[8];
		static std::string		_validTypes[4];
		bool					_isPseudoLiteral;
		void					_checkType(void);
		static isOfTypePointer	_isOfType[4];
		bool					_isChar(std::string const &str);
		bool					_isInt(std::string const &str);
		bool					_isFloat(std::string const &str);
		bool					_isDouble(std::string const &str);
};

#endif