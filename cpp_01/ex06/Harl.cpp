#include "Harl.hpp"

static	std::string levels[4] = {
	"debug",
	"info",
	"warning",
	"error"
};

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::_debug(void) {
	std::cout << "DEBUG: check if there are no missing commas" << std::endl;
	std::cout << "or brackets or parenthesis or whatever extra" << std::endl;
	std::cout << "signs you use for coding." << std::endl;
}

void	Harl::_info(void) {
	std::cout << "INFO: Those variables are uninitialized." << std::endl;
	std::cout << "If they were initialized I wouldn't be informing you otherwise." << std:: endl;
}

void	Harl::_warning(void) {
	std::cout << "WARNING: Are you sure you want me to compile your code?" << std::endl;
	std::cout << "It's full of syntax erros!!!" << std::endl;
}

void	Harl::_error(void) {
	std::cout << "ERROR: I told you there were error in your code." << std::endl;
	std::cout << "So no compilation for you today." << std:: endl;
}

void Harl::complain(std::string level) {
	switch (level) {
	case "debug":
		std::cout << "[ DEBUG ]" << std::endl;
		(this->*fptr[0])();
		/* fall through */
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		(this->*fptr[1])();
		/* fall through */
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		(this->*fptr[2])();
		/* fall through */
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		(this->*fptr[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
}
