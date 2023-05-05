#include "RPN.hpp"

int main(int argc, char**argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << "<RPN expression>" << std::endl;
		return (1);
	}


	RPN rpn;
	std::string rpn_exp = argv[1];
        rpn.validateInput(rpn_exp);



	return (0);
}