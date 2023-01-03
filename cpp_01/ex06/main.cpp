#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Yo're pretty stupid aren't you" << std::endl;
		return (0);
	}
	harl.complain(argv[1]);
}
