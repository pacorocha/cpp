/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:11:56 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/22 11:21:28 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include <string>
#include "Contact.class.hpp"

class PhoneBook {
public:
	PhoneBook( void );
	~PhoneBook( void );

	void	addNewContact( void );
	bool	run( void );
	void	searchContacts( void );
	void	printError( std::string str );
	void	print_column(std::string str);

private:
	Contact	_contacts[8];
	int		_total_contacts;
	int		_contact_indexer;
};

#endif
