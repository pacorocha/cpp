/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:12:00 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/20 20:22:20 by jfrancis         ###   ########.fr       */
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
		while (i < this->_total_contacts)
		{
			std::cout << std::setw(10) << std::right;
			std::cout << i + 1 << "|";
			std::cout << std::setw(10) << std::right;
			std::cout << this->_contacts[i].getFirstName() << "|";
			std::cout << std::setw(10) << std::right;
			std::cout << this->_contacts[i].getLastName() << "|";
			std::cout << std::setw(10) << std::right;
			std::cout << this->_contacts[i].getNickname() << std:: endl;
			i++;
		}
		std::cout << "Type the index of the contact to see all its data." << std::endl;
}
