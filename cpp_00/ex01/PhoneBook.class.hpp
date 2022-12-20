/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:11:56 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/19 20:43:41 by jfrancis         ###   ########.fr       */
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

private:
	Contact	_contacts[8];
	int		_total_contacts;
	int		_contact_indexer;
};

#endif