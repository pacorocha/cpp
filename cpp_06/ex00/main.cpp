#include "ScalarConverter.hpp"

static int	validInput(void) {
	std::cerr << "This program accepts only 1 argument." << std::endl;
	return (0);
}

static bool checkArgs(int argc) {
	if (argc !=2)
		return(true);
	return (false);
}

int main(int argc, char** argv) {
	if (checkArgs(argc))
		return (validInput());
	ScalarConverter::convert(argv[1]);
	return (0);
}
