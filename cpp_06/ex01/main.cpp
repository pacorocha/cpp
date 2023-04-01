#include "Serializer.hpp"

int	main(void) {
	uintptr_t	ptr = 0;
	Data		*test = new Data;

	test->x = 42;
	test->y = 32.42;
	test->str = "Actual coordenates are: ";

	std::cout << "Original pointer: " << ptr << std::endl;
	std::cout << "Original Data string: " << test->str << std::endl;
	std::cout << "Original Data x: " << test->x << std::endl;
	std::cout << "Original Data y: " << test->y << std::endl;
	ptr = Serializer::serialize(test);
	std::cout << "Serialized pointer: " << ptr << std::endl;
	std::cout << "Deserialized pointer: " << Serializer::deserialize(ptr) << std::endl;
	std::cout << "Deserialized pointer string: " << Serializer::deserialize(ptr)->str << std::endl;
	std::cout << "Deserialized pointer x: " << Serializer::deserialize(ptr)->x << std::endl;
	std::cout << "Deserialized pointer y: " << Serializer::deserialize(ptr)->y << std::endl;

	delete test;

	return (0);
}