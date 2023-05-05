#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return 1;
    }

	try {
    	BitcoinExchange exchange("data.csv", argv[1]);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

    return 0;
}