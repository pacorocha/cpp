/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:26:36 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/21 20:46:40 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact( void ) {
	return ;
}

Contact::~Contact()
{

}

void	Contact::setId( int id ) {
		this->_id = id;
}

void	Contact::setFirstName( void ) {
		std::string input;
		bool check = true;
		while (check)
		{
			input = getAlphaVar("First Name");
			check = checkEmptyString(input);
		}
		this->_first_name = input;
		input.clear();
}

void	Contact::setLastName( void ) {
		std::string input;
		bool check = true;
		while (check)
		{
			input = getAlphaVar("Last Name");
			check = checkEmptyString(input);
		}
		this->_last_name = input;
		input.clear();
}

void	Contact::setNickName( void ) {
		std::string input;
		bool check = true;
		while (check)
		{
			input = getAlphaVar("Nickname");
			check = checkEmptyString(input);
		}
		this->_nickname = input;
		input.clear();
}

void	Contact::setPhoneNumber( void ) {
		std::string input;
		bool check = true;
		while (check)
		{
			input = getNumericVar("Phone Number");
			check = checkEmptyString(input);
		}
		this->_phone_number = input;
		input.clear();
}

void	Contact::setDarkestSecret( void ) {
		std::string input;
		bool check = true;
		while (check)
		{
			input = getAlphaVar("Darkest Secret");
			check = checkEmptyString(input);
		}
		this->_darkest_secret = input;
		input.clear();
}

int	Contact::getId( void ) const {
	return this->_id;
}

std::string Contact::getFirstName( void ) const {
	return this->_first_name;
}

std::string Contact::getLastName( void ) const {
	return this->_last_name;
}

std::string Contact::getNickname( void ) const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber( void ) const {
	return this->_phone_number;
}

std::string Contact::getDarkestSecret( void ) const {
	return this->_darkest_secret;
}

std::string	Contact::getAlphaVar( std::string varname ) {
		std::string input;
		std::cout << "Please type contact's " << varname << ":" << std::endl;
		std::getline(std::cin, input);
		if (input.length() < 1 || !Contact::isAlphabetic(input))
			return (input = "");
		else
			return (input);
}

std::string	Contact::getNumericVar( std::string varname ) {
		std::string input;
		std::cout << "Please type contact's " << varname << ":" << std::endl;
		std::getline(std::cin, input);
		if (input.length() < 1 || !Contact::isNumeric(input))
			return (input = "");
		else
			return (input);
}

bool	Contact::isAlphabetic(std::string &str) {
		int flag = 0;
		for (size_t i = 0; i < str.length(); i++)
			if (!isalpha(str[i]))
				flag++;
		if (flag > 0)
			return (false);
		else
			return (true);
}

bool	Contact::isNumeric(std::string &str) {
		int flag = 0;
		for (size_t i = 0; i < str.length(); i++)
			if (!isdigit(str[i]))
				flag++;
		if (flag > 0)
			return (false);
		else
			return (true);
}

bool	Contact::checkEmptyString(std::string str) {
		if (str != "")
			return (false);
		else
			return (true);
}
