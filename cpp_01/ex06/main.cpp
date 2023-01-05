#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl harl;

	if (argc != 2)
	{
		std::cout << "You have to type 2 arguments" << std::endl;
		return (0);
	}
	harl.complain(argv[1]);
}
