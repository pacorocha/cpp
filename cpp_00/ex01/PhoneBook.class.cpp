/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:12:00 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/23 19:25:57 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook( void ) {
	this->_total_contacts = 0;
	this->_contact_indexer = 0;
	std::cout << "Welcome, I'm a VERY crappy PhoneBook!" << std::endl;
	std::cout << "You can only type 3 commands: ADD, SEARCH and EXIT." << std::endl;

	while (PhoneBook::run())
		continue ;
	return ;
}

PhoneBook::~PhoneBook( void ){
	std::cout << "All your contacts will be lost." << std::endl;
	std::cout << "Have a nice day!" << std::endl;
}

bool PhoneBook::run( void ) {
	std::string cmd;

	cmd.clear();
	std::getline(std::cin, cmd);
	if (cmd.empty())
			return (true);
	if (cmd == "ADD")
		PhoneBook::addNewContact();
	else if (cmd == "SEARCH")
		PhoneBook::searchContacts();
	else if (cmd == "EXIT")
		return (false);
	else
		std::cerr << "RTFM! You can only type ADD, SEARCH or EXIT!" << std::endl;
	return (true);
}

void	PhoneBook::addNewContact() {
	int id = this->_contact_indexer;
	this->_contacts[id].setFirstName();
	this->_contacts[id].setLastName();
	this->_contacts[id].setNickName();
	this->_contacts[id].setPhoneNumber();
	this->_contacts[id].setDarkestSecret();

	std::cout << "Contact Saved!" << std::endl;
	if (this->_contact_indexer == 7)
		this->_contact_indexer = 0;
	else
		this->_contact_indexer++;
	if (this->_total_contacts < 8)
		this->_total_contacts ++;
}

void	PhoneBook::searchContacts( void ) {
		int i = 0;
		int j;

		if (this->_total_contacts == 0)
			std::cout << "You don't have any contacts in your phonebook." << std::endl;
		else
		{
			while (i < this->_total_contacts)
			{
				std::cout << std::setw(10) << std::right;
				std::cout << i + 1 << " | ";
				print_column(this->_contacts[i].getFirstName());
				print_column(this->_contacts[i].getLastName());
				print_column(this->_contacts[i].getNickname());
				std::cout << std::endl;
				i++;
			}
			std::cout << "Type the index of the contact to see all its data." << std::endl;
			std::cin >> j;
			while (1)
			{
				if(std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(__INT_MAX__,'\n');
					printError("Input is not a valid integer.");
					std::cin >> j;
				}
				if (j < 1 || j > 8 || j > this->_total_contacts)
				{
					std::cin.clear();
					printError("That is not a valid contact index. Type a valid integer.");
					std::cin >> j;
				}
				if (!std::cin.fail())
				{
					std::cout << "First name: " << this->_contacts[j - 1].getFirstName() << std::endl;
					std::cout << "Last name: " << this->_contacts[j - 1].getLastName() << std::endl;
					std::cout << "Nickname: " << this->_contacts[j - 1].getNickname() << std::endl;
					std::cout << "Phone Number: " << this->_contacts[j - 1].getPhoneNumber() << std::endl;
					std::cout << "Darkest Secret: " << this->_contacts[j - 1].getDarkestSecret() << std::endl;
					break ;
				}
			}
		}
}

void PhoneBook::print_column(std::string str) {
	std::cout << std::setw(10) << std::right;
	if (str.size() > 9)
		std::cout << str.substr(0, 9) + (std::string)"." << " | ";
	else
		std::cout << str << " | ";
}

void	PhoneBook::printError( std::string str ) {
		std::cerr << "Error: " << str << std::endl;
}
