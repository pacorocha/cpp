/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:29:01 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/06 17:41:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string Harl::levels[4] = {
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
	complains complains[4] = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			(this->*(complains[i]))();
}
