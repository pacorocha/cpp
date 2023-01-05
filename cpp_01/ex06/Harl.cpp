/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:29:54 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/05 17:29:57 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string	Harl::levels[4] = {
	"debug",
	"info",
	"warning",
	"error"
};

Harl::complainsPointer	Harl::complains[4] = {
	&Harl::_debug,
	&Harl::_info,
	&Harl::_warning,
	&Harl::_error
};

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::_debug(void) const {
	std::cout << "DEBUG: check if there are no missing commas" << std::endl;
	std::cout << "or brackets or parenthesis or whatever extra" << std::endl;
	std::cout << "signs you use for coding." << std::endl;
}

void	Harl::_info(void) const {
	std::cout << "INFO: Those variables are uninitialized." << std::endl;
	std::cout << "If they were initialized I wouldn't be informing you otherwise." << std:: endl;
}

void	Harl::_warning(void) const {
	std::cout << "WARNING: Are you sure you want me to compile your code?" << std::endl;
	std::cout << "It's full of syntax erros!!!" << std::endl;
}

void	Harl::_error(void) const {
	std::cout << "ERROR: I told you there were error in your code." << std::endl;
	std::cout << "So no compilation for you today." << std:: endl;
}

void Harl::complain(std::string level) {
	int	i = -1;

	while (++i < 4) {
		if (!level.compare(this->levels[i]))
			break;
	}

	switch (i) {
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		(this->*complains[0])();
		/* no break command, so will fall through */
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		(this->*complains[1])();
		/* no break command, so will fall through */
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		(this->*complains[2])();
		/* no break command, so will fall through */
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		(this->*complains[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
}
