#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	srand(time(0));
	unsigned int seed = rand() % 4;

	if (seed == 0)
		return new A;
	else if (seed == 1)
		return new B;
	else if (seed == 2)
		return new C;
	else {
		std::cout << "Error: object pointer couldn't be generated." << std::endl;
		return NULL;
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "The object pointer is type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The object pointer is type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The object pointer is type C" << std::endl;
	else
		std::cout << "Error: Couldn't identify pointer" << std::endl;
}

void	identify(Base& p) {
	try {
		A AI = dynamic_cast<A&>(p);
		std::cout << "This object reference is type A" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "catch A: " << e.what() << std::endl;
	}
	try {
		B BI = dynamic_cast<B&>(p);
		std::cout << "This object reference is type B" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "catch B: " << e.what() << std::endl;
	}
	try {
		C CI = dynamic_cast<C&>(p);
		std::cout << "This object reference is type C" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "catch C: " << e.what() << std::endl;
	}
}

int main(void) {
	Base* ptr = generate();

	if (!ptr)
		return (1);
	Base& ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
	return (0);
}