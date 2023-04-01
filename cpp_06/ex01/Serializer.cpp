#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
}


// Destructor
Serializer::~Serializer()
{
}


// Operators
Serializer & Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return *this;
}

