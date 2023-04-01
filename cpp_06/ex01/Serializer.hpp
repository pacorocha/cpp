#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>


struct Data {
	int			x;
	double		y;
	std::string	str;
};

class Serializer
{
	public:
		// Destructor
		~Serializer();

		// Methods
		static uintptr_t serialize(Data* ptr) {
			return reinterpret_cast<uintptr_t>(ptr);
		}

		static Data* deserialize(uintptr_t raw) {
			return reinterpret_cast<Data*>(raw);
		}
	private:
		// Constructors
		Serializer();
		Serializer(const Serializer &copy);

		// Operators
		Serializer &operator=(const Serializer &assign);
};

#endif